# IoT Engineer Task
In this project we are to implement a secure communication protocol.<br />
Firstly, when the mobile application sends a request, the “receivedCallback”
Callback is called by the request. In this function, We need to decrypt the callback data received,
and then, the data is deserialized to extract the parameters in order to use in the
“handleCommand” function parameters.<br />
The “handleCommand” function handles the run of corresponding command. We assume
that each Id corresponds to a command. Hence, In order to run the corresponding command, a
function pointer is used (called *functionPointer). In addition, a structure called “commandStruct”
has been developed, which implements the proposed function according to the action ID.<br />
We also have a few functions that each of them corresponds to a specific command (the
functionPointer points to one of them each time). We proposed four functions for instance as:
addPasscode, deletePasscode, getBatteryStatus, and openDoor; but in fact, there should be as many.
functions as commands, far more than these four. When the task of these functions is done, For optimization we must fill buffer completely and Finally
we call the ”closeResponse” function to send a response to the client.in main loop as soon as the conditions are met, the response is done.<br />

## Project structure and architecture
The overall structure of the project is implemented in the flowchart below.<br />
The project has three files that are executed in the main.c file of the program's routine. Also, the file test_project.h has headers and function prototypes as well as structures and test_project.c include variables and functions body.



![Project Structure](https://user-images.githubusercontent.com/30548915/202768862-a436cd14-f056-4334-83a9-f18026f85f4f.jpg)<br /><br /><br />


## Naming Convention
### Functions
the name of the function hint at what it does.The first character of function argument names will be lowercase. Each word should also begin with a capital letter. 
```
void getBatteryStatus(char *Payload);
```

### Variables
No special symbols can be used in variable names except for the underscore(‘_’). No keywords can be used for variable names. Also digits may be used but only after the alphabet.
```
bool open_to_response = false;
bool send_response = false;
```
### Structures 
Also, in this project, the names of structures follow the naming convention for functions. 
```
typedef struct
{
  idnum action_ID;
  char action_payload[200];
} payloadReceive;
```
### File Naming
No special character is allowed in the file name except for underscore (‘_’) and dash (‘-‘).
The file name will end with the .c extension.
```
test_project.c
```

