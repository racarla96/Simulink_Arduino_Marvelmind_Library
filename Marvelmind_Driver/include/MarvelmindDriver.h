//MarvelmindDriver.h
#ifndef _MARVELMINDDRIVER_H_
#define _MARVELMINDDRIVER_H_
#ifdef __cplusplus
extern "C" {
#endif
    #if (defined(MATLAB_MEX_FILE) || defined(RSIM_PARAMETER_LOADING) ||  defined(RSIM_WITH_SL_SOLVER))
        /* This will be run in Rapid Accelerator Mode */
        #define colorSensor_Init(a)        (0)
        #define colorSensor_Step(a,b,c)    (0)
        #define colorSensor_Terminate()    (0)
    #else
        #include <stdint.h>

        void MarvelmindDriver_Init(int8_t);
        void MarvelmindDriver_Step(int8_t*, uint32_t*, uint32_t*, uint32_t *, uint32_t*) ;
        void MarvelmindDriver_Terminate(void);
#endif
#ifdef __cplusplus
}
#endif
#endif 