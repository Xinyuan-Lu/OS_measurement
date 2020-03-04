all: a_measOverhead b_procCall c_sysCall d_taskCreation e_contextSwitch

clean:
	rm -f a_measOverhead b_procCall c_sysCall d_taskCreation e_contextSwitch

a_measOverhead: a_measOverhead.c
	gcc -o a_measOverhead a_measOverhead.c -Wall

b_procCall: b_procCall.c
	gcc -o b_procCall b_procCall.c -Wall

c_sysCall: c_sysCall.c
	gcc -o c_sysCall c_sysCall.c -Wall

d_taskCreation: d_taskCreation.c
	gcc -o d_taskCreation d_taskCreation.c -Wall

e_contextSwitch: e_contextSwitch.c
	gcc -o e_contextSwitch e_contextSwitch.c -Wall