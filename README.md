# CS225 Final Project
## ycchang4-bohan3-mingw4-jialen2
### How to use our program:
Command:  
* ```make``` generates an executable named main in ```./```directory.
* ```make test``` generates a test executable named main in ```./```directory.
* ```make data``` generates made-up test data  in ```./```directory.
* ```make clean``` removes all object files in ```./```directory.

Arguments:
+ ```./main``` runs the program with all default arguments. To use your arguments follow instructions:
 - ```-LFprots <file_path>``` gives the location the formatted csv containing airport data.
 - ```-LFroutes <file_path>``` gives the location of the formatted csv containing route data.
 - ```-from <IATA>``` gives the IATA code for your starting airport. (https://en.wikipedia.org/wiki/IATA_airport_code)
 - ```-to <IATA>``` gives the IATA code for your destination airport.
 - ```-l``` enables the landmark functionality. 
 	> With landmark enabled, the program will ask for landmark entries once ready. Type IATA one at a time and use enter to submit. Use "X" to end landmark entries (no quotation mark).

Required Data Format:
* The airport data should be a csv file. Sample entry:  
```0001,"Shanghai Pudong International Airport","Shanghai","China","PVG","ZSPD",31.143400192260742,121.80500030517578,13,8,"U","Asia/Shanghai","airport","OurAirports"```  
Each line has one entry. 



 
 




