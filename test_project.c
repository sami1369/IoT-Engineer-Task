#include <test_project.h>
#include <stdio.h>

bool open_to_response = false;
bool send_response = false; // allowing Send client report

char buffer[buffer_size];
size_t buffer_pos = 0;

/**
 * @brief CommandHandler_handle function handle run of the corresponding command
 *
 * @param Id is an enum that start from 1 and each number corresponds to a command
 * @param Payload contain data to implementation of an instruction based on the corresponding command
 */
void handleCommand(idnum Id, char *Payload)
{
  if (buffer_pos < buffer_size)
  {
    int i = 0;
    while (commands[i].execute > 0)
    {
      if (commands[i].ID == Id)
      {
        openResponse();
        (*commands[i].execute)(Payload);
        return;
      }
      i++;
    }
  }
  else
  {
    closeResponse();
  }
}

/**
 * @brief append a list item to our response
 * 
 * @param data the data need to response related to each command
 * @param Id   ID corresponds to command and we return to client for more easily parse
 * @param length sizeof data to fill buffer
 * @return size_t size of buffer after snprintf
 */
size_t appendDataToResponse(char *data, idnum Id, size_t length)
{
  return (snprintf(buffer, length, "ID : %d data : %s", Id, data) < buffer_size)
}

/**
 * @brief Function to start the response
 */
void openResponse()
{
  open_to_response = true;
}

/**
 * @brief Function to close the response
 *
 */
void closeResponse();
{
  open_to_response = false;
  send_response = true;
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
  printf("Start Time is %d\n", connect->start_time);
  printf("End Time is  %d\n", connect->end_time);
  buffer_pos += appendDataToResponse((char)connect->passCode, ID, buffer_size - buffer_pos);
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
  buffer_pos += appendDataToResponse("Passcode Deleted", ID, buffer_size - buffer_pos);
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
  buffer_pos += appendDataToResponse((char)connect->battery_state, ID, buffer_size - buffer_pos);
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
  printf("door State  %d\n", connect->open_door);
  printf("Start Time is %d\n", connect->start_time);
  printf("End Time is  %d\n", connect->end_time);
  buffer_pos += appendDataToResponse(connect->open_door + '0', ID, buffer_size - buffer_pos);
}