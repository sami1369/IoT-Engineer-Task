#include <test_project.h>

/**
 * @brief callback for receive data from client
 * Start Point
 * first  decrypt data
 * deserialize data to extract parameters to use in handleCommand_handle function
 * @param data an encrypted data from client
 * @param length size of data
 */
  receivedCallback(uint8_t *data, uint16_t length)(
  decryptPayload(data, length, output); // decrypt the callback data received
  payloadReceive *payload = NULL;
  payload = (payloadReceive *)output; // Casting received data(Deserialization)
  handleCommand(payload->action_ID, payload->action_payload);
)

int main()
{
  while (1)
  {
    if (open_to_responseResponse == false && send_response == true)
    {
      // Start to Response to the client
      encryptPayload(buffer, length, output);
      sendDataToClient(output, length);
      memset(buffer, 0, buffer_size);
      send_response == false;
    }
  }
}