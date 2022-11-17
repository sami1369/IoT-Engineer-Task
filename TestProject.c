#include <TestProject.h>
#include <stdio.h>


bool openToResponse = false;
bool sendResponse = false; // allowing Send client report


/**
 * @brief CommandHandler_handle function handle run of the corresponding command
 *
 * @param Id is an enum that start from 1 and each number corresponds to a command
 * @param Payload contain data to implementation of an instruction based on the corresponding command
 */
CommandHandler_handle(idnum Id, char *Payload)
{
  int i = 0;
  while (commands[i].execute > 0)
  {
    if (commands[i].ID == Id)
    {  
      Communication_openResponse();
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
    PacketRecieve *packRecieve = NULL;
    packRecieve = (PacketRecieve *)output; // Casting received data(Deserialization)
    CommandHandler_handle(packRecieve->actionId, packRecieve->actionPayload);
)

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
void getBatteryStatus(char *Payload)
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