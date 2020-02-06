#ifndef IHM_H
#define IHM_H


extern "C"{
#include <curses.h>
#include <libARSAL/ARSAL.h>
}
typedef enum
{
    IHM_INPUT_EVENT_NONE,
    IHM_INPUT_EVENT_EXIT,
    IHM_INPUT_EVENT_EMERGENCY,
    IHM_INPUT_EVENT_TAKEOFF,
    IHM_INPUT_EVENT_LAND,
    IHM_INPUT_EVENT_UP,
    IHM_INPUT_EVENT_DOWN,
    IHM_INPUT_EVENT_RIGHT,
    IHM_INPUT_EVENT_LEFT,
    IHM_INPUT_EVENT_FORWARD,
    IHM_INPUT_EVENT_BACK,
    IHM_INPUT_EVENT_ROLL_LEFT,
    IHM_INPUT_EVENT_ROLL_RIGHT,
}eIHM_INPUT_EVENT;

typedef void (*IHM_onInputEvent_t) (eIHM_INPUT_EVENT event, void *customData);

typedef struct
{
    WINDOW *mainWindow;
    ARSAL_Thread_t inputThread;
    int run;
    IHM_onInputEvent_t onInputEventCallback;
    void *customData;
}IHM_t;

IHM_t *IHM_New (IHM_onInputEvent_t onInputEventCallback);
void IHM_Delete (IHM_t **ihm);

void IHM_setCustomData(IHM_t *ihm, void *customData);

void IHM_PrintHeader(IHM_t *ihm, char *headerStr);
void IHM_PrintInfo(IHM_t *ihm, char *infoStr);
void IHM_PrintBattery(IHM_t *ihm, uint8_t percent);



#endif // IHM_H
