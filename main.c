#include <stdio.h>
bool openToResponse = false;
bool sendReport = false; // allowing Send client report

// enum to associate an ID with command
typedef enum
{
  addPasscode = 1,
  ADDITION,
} idnum;

/**
 * @brief struct of payload
 * Due to the fact that I dont know about the data received format,the variables are hypothetical
 */
typedef struct
{
  char passCode[10];
  uint8_t startTime;
  uint8_t endTime;
  uint8_t batteryState; // in percent
  uint8_t openDoor;     // 1 means door must open
} Packet;

/**
 * @brief Pointer function to call a function related command
 */
typedef void (*functionPointer)(void);

struct commandStruct
{
  idnum ID;                    // Assume be a relationship between actionID and command
  functionPointer execute; // According to the received ID, it points to a function corresponding to the command
};

/**
 * @brief One of the functions that the pointer function points to
 *
 * @param Payload contain data to implementation of an instruction based on the corresponding command
 */
void addPasscode(char *Payload)
{
  printf("%s\n", Payload);
  Packet *packet = NULL;
  packet = (Packet *)Payload;
  // Here I access the different fields of the packet using the Packet struct
  printf("Passcode is %s\n", connect->passCode);
  printf("Start Time is %d\n", connect->startTime);
  printf("End Time is  %d\n", connect->endTime);
  Communication_closeResponse();
}

/**
 * @brief One of the functions that the pointer function points to
 *
 * @param Payload contain data to implementation of an instruction based on the corresponding command
 */
void deletePasscode(char *Payload)
{
  printf("%s\n", Payload);
  Packet *packet = NULL;
  packet = (Packet *)Payload;
  Communication_closeResponse();
}

/**
 * @brief One of the functions that the pointer function points to
 *
 * @param Payload contain data to implementation of an instruction based on the corresponding command
 */
void batteryStatus(char *Payload)
{
  printf("%s\n", Payload);
  Packet *packet = NULL;
  packet = (Packet *)Payload;
  // Here I access the different fields of the packet using the Packet struct
  printf("Battery Status is  %d\n", connect->endTime);
  Communication_closeResponse();
}

/**
 * @brief One of the functions that the pointer function points to
 *
 * @param Payload contain data to implementation of an instruction based on the corresponding command
 */
void openDoor(char *Payload);
{
  printf("%s\n", Payload);
  Packet *packet = NULL;
  packet = (Packet *)Payload;
  // Here I access the different fields of the packet using the Packet struct
  printf("door State  %d\n", connect->openDoor);
  printf("Start Time is %d\n", connect->startTime);
  printf("End Time is  %d\n", connect->endTime);
  Communication_closeResponse();
}

/**
 * @brief commandstruct is executed according to the action ID
 * Assume be a relationship between actionID and command
 * According to the desired ID that is related to a command,
 * the corresponding function will be executed.
 */
const struct commandStruct commands[] = {
    {1, &addPasscode},
    {2, &deletePasscode},
    {3, &batteryStatus},
    {4, &openDoor},
    {0, 0} // End of table indicator. MUST BE LAST!!!
};

// struct to cast date received
typedef struct
{
  idnum actionId;
  char actionPayload[200];
} PacketRecieve;

PacketRecieve *packet_recieve;

/**
 * @brief CommandHandler_handle function handle run of the corresponding command
 *
 * @param Id is an enum that start from 1 and each number corresponds to a command
 * @param Payload contain data to implementation of an instruction based on the corresponding command
 */
CommandHandler_handle(idnum Id, char *Payload)
{
  Communication_openResponse();
  int i = 0;
  while (commands[i].execute > 0)
  {
    if (commands[i].ID == Id)
    {
      (*commands[i].execute)(Payload);
      return;
    }
    i++;
  }
}
/**
 * @brief call function to start the response
 */
void Communication_openResponse()
{
  openToResponse = true;
}
/**
 * @brief call this function to close the response
 *
 */
void Communication_closeResponse();
{
  openToResponse = false;
  sendReport = true;
}

/**
 * @brief callback for receive data from client
 * Start Point
 * first  decrypt data
 * deserialize data to extract parameters to use in CommandHandler_handle function
 * @param data an encrypted data from client
 * @param length size of data
 */
Communication_onDataReceived(uint8_t *data, uint16_t length)(
    decrypt(data, length, output); // decrypt the callback data received
    PacketRecieve *packet_recieve = NULL;
    packet_recieve = (PacketRecieve *)output; // Casting received data(Deserialization)
    CommandHandler_handle(packet_recieve->actionId, packet_recieve->actionPayload);
)

int main()
{
  while (1)
  {
    if (openToResponse == false && sendReport == true)
    {
      // Start to report the client by sending ok
      encrypt("ok", length, output);
      Communication_sendData(output, length);
      sendReport == false;
    }
  }
}