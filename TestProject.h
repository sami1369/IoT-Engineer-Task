#ifndef _TESTPROJECT_H
#define _HTESTPROJECT_H

#define bufferSize 256
/**
 * @brief commandstruct is executed according to the action ID
 * Assume be a relationship between actionID and command
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
    idnum ID;                // Assume be a relationship between actionID and command
    functionPointer execute; // According to the received ID, it points to a function corresponding to the command
};

// struct to cast date received
typedef struct
{
    idnum actionId;
    char actionPayload[200];
} PacketRecieve;

void encrypt(uint8_t *input, uint8_t length, uint8_t *output);
void decrypt(uint8_t *input, uint8_t length, uint8_t *output);

void Communication_onDataReceived(idnum Id, char *Payload);
void Communication_sendData(uint8_t *data, uint16_t length);

void CommandHandler_handle(uint8_t actionId, char *actionPayload);

void Communication_openResponse();

void Communication_appendResponse(char *data, idnum Id, size_t length);

void Communication_closeResponse();

void addPasscode(char *Payload);
void deletePasscode(char *Payload);
void getBatteryStatus(char *Payload);
void openDoor(char *Payload);


#endif