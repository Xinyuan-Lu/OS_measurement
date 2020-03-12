all: a_measOverhead b_procCall c_sysCall d_taskCreation e_contextSwitch e_contextSwitch_pthread

clean:
	rm -f a_measOverhead b_procCall c_sysCall d_taskCreation e_contextSwitch

a_measOverhead: a_measOverhead.c
	gcc -O0 -o a_measOverhead a_measOverhead.c -Wall

b_procCall: b_procCall.c
	gcc -O0 -o b_procCall b_procCall.c -Wall

c_sysCall: c_sysCall.c
	gcc -O0 -o c_sysCall c_sysCall.c -Wall

d_taskCreation: d_taskCreation.c
	gcc -O0 -pthread -o d_taskCreation d_taskCreation.c -Wall

e_contextSwitch: e_contextSwitch.c
	gcc -O0 -o e_contextSwitch e_contextSwitch.c -Wall

e_contextSwitch_pthread: e_contextSwitch_pthread.c
	gcc -pthread -O0 -o e_contextSwitch_pthread e_contextSwitch_pthread.c -Wall