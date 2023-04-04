#include <stdio.h>
#include "receiver.h"


int main(int argc, char **argv)
{
    Data sensor_A;
    Data sensor_B;

    getData(sensor_A.data_received, sensor_B.data_received);
    print_all_Data(sensor_A.data_received, sensor_B.data_received);
    
    sensor_A.max = get_max(sensor_A.data_received);
    sensor_A.min = get_min(sensor_A.data_received);
    sensor_A.SMA = get_SMA(sensor_A.data_received);

    sensor_B.max = get_max(sensor_B.data_received);
    sensor_B.min = get_min(sensor_B.data_received);
    sensor_B.SMA = get_SMA(sensor_B.data_received);

    printf( "Sensor A: min=%d max=%d SMA=%d\n", sensor_A.min, sensor_A.max, sensor_A.SMA );
    printf( "Sensor B: min=%d max=%d SMA=%d\n", sensor_B.min, sensor_B.max, sensor_B.SMA );

    return 0;
}
