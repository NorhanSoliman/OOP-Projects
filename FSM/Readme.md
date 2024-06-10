##To Run:
- Compile all source files to create the executable.
- Or run the attached executable directly.
- Then enter the name of two fsm files in the same directory:
	- The first FSM file is used as a fallback if the second FSM 	file jumps to it using the JMP0 action.

	-The second FSM file is the main FSM that will be 		executed.

##Limitation: 
- The simulator requires the name of two FSM files to handle and test the JMP0 action properly.
- The first FSM file (fsm1.fsm) is only used if the second FSM (fsm2.fsm) jumps to it during execution.


##Input Format
- FSM Definition: The file starts with FSM <name>.
- Variables: Declared with VAR <var1>, <var2>, ....
- States: Defined within STATES: block with each state enclosed in brackets and followed by actions.
- Transitions: Defined within TRANSITIONS: block in the format [input] <source> >> <destination>.

###Check the Report for details and examples.