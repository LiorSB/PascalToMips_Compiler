# PascalToMips_Compiler
Project that translates Pascal syntax into MIPS using Bison and Flex and writing in Lex, Yacc and C.
<br/>
<br/>
## How to use:
Only 1 arguement is allowed after cpm.exe and it must be a *.cpl file.<br/>
The CPL file must be written in Pascal syntax to compile to mips, otherwise only a file called listing.lst will be the only output with the fitting errors.
In case everything runs well the out will be two files: listing.lst and mips.s.
The mips.s file you may run in MARS.
<br/><br/>
### **Successful example:**

![image](https://user-images.githubusercontent.com/92099051/165169184-18bd6e80-058e-4bd6-a729-14a5686d337e.png)

![image](https://user-images.githubusercontent.com/92099051/165169121-e30b25ef-b328-440f-92b7-42335feb44bf.png)

![image](https://user-images.githubusercontent.com/92099051/165169245-db639606-faec-4c9d-a2a6-f167dc0c701c.png)

![image](https://user-images.githubusercontent.com/92099051/165169561-82996af4-43db-4ecc-98d1-e762bff5f162.png)

![image](https://user-images.githubusercontent.com/92099051/165169605-a4b23563-c5d5-4716-bd86-c05258926c9b.png)

![image](https://user-images.githubusercontent.com/92099051/165169665-67ebacf8-712a-4c2c-94fd-b8f9537af3de.png)
<br/><br/>
### **Error example:**
Not declaring a variable and not ending a line with ';'

![image](https://user-images.githubusercontent.com/92099051/165170725-de2a9881-3e12-43f4-a603-c50b90032a58.png)

![image](https://user-images.githubusercontent.com/92099051/165170680-525bcc43-c7f5-4158-8cba-1ddae1ab5cf0.png)

![image](https://user-images.githubusercontent.com/92099051/165170797-8c87f939-a209-4e51-9d01-e3ec54efebf9.png)
