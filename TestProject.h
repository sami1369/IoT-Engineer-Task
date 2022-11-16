#ifndef _TESTPROJECT_H 
#define _HTESTPROJECT_H
void encrypt(uint8_t* input, uint8_t length, uint8_t* output);
void decrypt(uint8_t* input, uint8_t length, uint8_t* output);

void Communication_onDataReceived(uint8_t* data, uint16_t length);
void Communication_sendData(uint8_t* data, uint16_t length);

void CommandHandler_handle( uint8_t actionId, uint8_t* actionPayload);

void Communication_openResponse();

void Communication_appendResponse(uint8_t* data, uint8_t length);

void Communication_closeResponse();

#endif