
#ifndef TEST_PROJECT_H
#define TEST_PROJECT_H

#define buffer_size 256

/**
 * @brief commandstruct is executed according to the action ID
 * Assume be a relationship between action_ID and command
 * According to the desired ID that is related to a command,
 * the corresponding function will be executed.
 */
const struct commandStruct commands[] = {
    {1, &addPasscode},
    {2, &deletePasscode},
    {3, &getBatteryStatus},
    {4, &openDoor},
    {0, 0} // End of table indicator. MUST BE LAST!!!
};

// enum to associate an ID with command
typedef enum
{
  addPassCode = 1,
  ADDITION,
} idnum;

/**
 * @brief struct of payload
 * Due to the fact that I dont know about the data received format,the variables are hypothetical
 */
typedef struct
{
  char pass_code[10];
  uint8_t start_time;
  uint8_t end_time;
  uint8_t battery_state; // in percent
  uint8_t open_door;     // 1 means door must open
} packet;

/**
 * @brief Pointer function to call a function related command
 */
typedef void (*functionPointer)(void);

struct commandStruct
{
  idnum ID;                // Assume be a relationship between action_ID and command
  functionPointer execute; // According to the received ID, it points to a function corresponding to the command
};

// struct to cast date received
typedef struct
{
  idnum action_ID;
  char action_payload[200];
} payloadReceive;

void encryptPayload(uint8_t *input, uint8_t length, uint8_t *output);
void decryptPayload(uint8_t *input, uint8_t length, uint8_t *output);

void receivedCallback(idnum Id, char *Payload);
void sendDataToClient(uint8_t *data, uint16_t length);

void handleCommand(uint8_t action_ID, char *action_payload);

void openResponse();

size_t appendDataToResponse(char *data, idnum Id, size_t length);

void closeResponse();

void addPasscode(char *Payload);
void deletePasscode(char *Payload);
void getBatteryStatus(char *Payload);
void openDoor(char *Payload);

#endif