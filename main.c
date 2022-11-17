#include <TestProject.h>

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