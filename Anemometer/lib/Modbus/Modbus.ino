#include "SimpleModbusMaster.h"

/* To communicate with a slave you need to create a
   packet that will contain all the information
   required to communicate to that slave.

   There are numerous counters for easy diagnostic.
   These are variables already implemented in a
   packet. You can set and clear these variables
   as needed.

   There are general modbus information counters:
   requests - contains the total requests to a slave
   successful_requests - contains the total successful requests
   total_errors - contains the total errors as a sum
   timeout - contains the total time out errors
   incorrect_id_returned - contains the total incorrect id returned errors
   incorrect_function_returned - contains the total incorrect function returned errors
   incorrect_bytes_returned - contains the total incorrect bytes returned errors
   checksum_failed - contains the total checksum failed errors
   buffer_errors - contains the total buffer errors

   And there are modbus specific exception counters:
   illegal_function - contains the total illegal function errors
   illegal_data_address - contains the total illegal data_address errors
   illegal_data_value - contains the total illegal data value errors
   misc_exceptions - contains the total miscellaneous returned exceptions

   And finally there is a variable called "connection" that
   at any given moment contains the current connection
   status of the packet. If true then the connection is
   active if false then communication will be stopped
   on this packet untill the programmer sets the "connection"
   variable to true explicitly. The reason for this is
   because of the time out involved in modbus communication.
   EACH faulty slave that's not communicating will slow down
   communication on the line with the time out value. E.g.
   Using a time out of 1500ms, if you have 10 slaves and 9 of them
   stops communicating the latency burden placed on communication
   will be 1500ms * 9 = 13,5 seconds!!!!

   modbus_update() returns the previously scanned false connection.
   You can use this as the index to your packet array to find out
   if the connection has failed in that packet and then react to it.
   You can then try to re-enable the connecion by setting the
   packet->connection attribute to true.
   The index will only be available for one loop cycle, after that
   it's cleared and ready to return the next false connection index
   if there is one else it will return the packet array size indicating
   everything is ok.

   All the error checking, updating and communication multitasking
   takes place in the background!

   In general to communicate with to a slave using modbus
   RTU you will request information using the specific
   slave id, the function request, the starting address
   and lastly the number of registers to request.
   Function 3 and 16 are supported. In addition to
   this broadcasting (id = 0) is supported on function 16.
   Constants are provided for:
   Function 3 -  READ_HOLDING_REGISTERS
   Function 16 - PRESET_MULTIPLE_REGISTERS

   The example sketch will read a packet consisting
   of 9 registers from address 0 using function 3 from
   the SimpleModbusSlave example and then write
   another packet containing a value to toggle the led.s
*/

//////////////////// Port information ///////////////////
#define baud 4800
#define timeout 1000
#define polling 200 // the scan rate
#define MODBUS_SERIAL (Stream*)&Serial1

// If the packets internal retry register matches
// the set retry count then communication is stopped
// on that packet. To re-enable the packet you must
// set the "connection" variable to true.
#define retry_count 10

// used to toggle the receive/transmit pin on the driver
#define TxEnablePin 0

// This is the easiest way to create new packets
// Add as many as you want. TOTAL_NO_OF_PACKETS
// is automatically updated.
enum {
    PACKET1,
    // PACKET2,
    // leave this last entry
    TOTAL_NO_OF_PACKETS
};

// Create an array of Packets for modbus_update()
Packet packets[TOTAL_NO_OF_PACKETS];

// Create a packetPointer to access each packet
// individually. This is not required you can access
// the array explicitly. E.g. packets[PACKET1].id = 2;
// This does become tedious though...
packetPointer packet1 = &packets[PACKET1];
// packetPointer packet2 = &packets[PACKET2];

// The data from the PLC will be stored
unsigned int windSpeed[2];
unsigned long last_toggle = millis();

void setup()
{
    /**
     * @brief 
     * doc: https://media.digikey.com/pdf/Data%20Sheets/Seeed%20Technology/Wind_Speed_Transmitter_485Type_V1.0_UG.pdf
     */

    Serial.begin(115200);
    
    packet1->id = 0;
    packet1->function = READ_HOLDING_REGISTERS;
    packet1->address = 0;
    packet1->no_of_registers = 2;
    packet1->register_array = windSpeed;
    /**
     * doc: https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/
     * for config setup
     */
    modbus_configure(MODBUS_SERIAL, 4800, SERIAL_8N1, timeout, polling, retry_count, 0, packets, TOTAL_NO_OF_PACKETS);
}

void loop()
{
    unsigned int connection_status = modbus_update(packets);

    if (millis() - last_toggle > 1000) {
        Serial.print(F("windSpeed:"));
        Serial.print(windSpeed[0]);
        Serial.print(" ");
        Serial.println(windSpeed[1]);

        last_toggle = millis();
    }
}
