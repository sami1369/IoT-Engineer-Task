#include <TestProject.h>
#include <stdio.h>


bool openToResponse = false;
bool sendResponse = false; // allowing Send client report

char buffer[bufferSize];
size_t bufferPos = 0;

/**
 * @brief CommandHandler_handle function handle run of the corresponding command
 *
 * @param Id is an enum that start from 1 and each number corresponds to a command
 * @param Payload contain data to implementation of an instruction based on the corresponding command
 */
CommandHandler_handle(idnum Id, char *Payload)
{  
  if(bufferPos < bufferSize )
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
  else {
    Communication_closeResponse();
  }
}

size_t Communication_appendResponse(char *data, idnum Id ,size_t length){
  return (snprintf(buffer, length,"ID : %d data : %s", Id, data) < bufferSize)
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
  bufferPos += Communication_appendResponse ((char) connect->passCode , ID ,bufferSize - bufferPos);  
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
  bufferPos += Communication_appendResponse ("Passcode Deleted" , ID ,bufferSize - bufferPos);
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
  bufferPos += Communication_appendResponse ((char) connect->batteryState , ID ,bufferSize - bufferPos);

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
  bufferPos += Communication_appendResponse (connect->openDoor + '0' , ID ,bufferSize - bufferPos);
}