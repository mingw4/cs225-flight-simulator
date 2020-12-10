# CS225 Final Project
## ycchang4-bohan3-mingw4-jialen2
### How to use our program:  
  
#### Command:  
* ```make``` generates an executable named main in ```./```directory.
* ```make test``` generates a test executable named test in ```./```directory.
* ```make data``` generates made-up test data  in ```./```directory.
* ```make clean``` removes all object files in ```./```directory.
---
#### Arguments:
+ ```./main``` runs the program with all default arguments. To use your arguments follow instructions:
 - ```-LFprots <file_path>``` gives the location the formatted csv containing airport data.
 - ```-LFroutes <file_path>``` gives the location of the formatted csv containing route data.
 - ```-from <IATA>``` gives the IATA code for your starting airport. (https://en.wikipedia.org/wiki/IATA_airport_code)
 - ```-to <IATA>``` gives the IATA code for your destination airport.
 - ```-l``` enables the landmark functionality. 
 	> With landmark enabled, the program will ask for landmark entries once ready. Type IATA one at a time and use enter to submit. Use "X" to end landmark entries (no quotation mark).
---
#### Required Data Format: (Invalid lines shall be omitted but may not break the program until you use it)
* The airport data should be a csv file. Sample entry:  
```0001,"Shanghai Pudong International Airport","Shanghai","China","PVG","ZSPD",31.143400192260742,121.80500030517578,13,8,"U","Asia/Shanghai","airport","OurAirports"```  
Each line has one entry.  
* * The minimum requirement is the following:  
the 0th column is a unique integer value.  
The 4th column is the IATA with quotation mark.
The 6th and 7th are valid latitude and longitude. 
* The route data should be a csv file. Sample entry:  
```CA,002,JFK,1000,PVG,0001,,0,380```  
* * The minimum requirement is the following:  
The 0th entry is the airline indentifyer.
The 3rd entry is the unique integer id that corresponds to to the IATA.  
The 5rd entry is the unique integer id that corresponds to to the IATA.  
The 7th entry is an integer value of stops in the travel.

---
#### Output:
* Sample output:  
```
>> ./main -from "HND" -to "PVG"
Result:
"HND"->"FUK" with the following choice of airline and aircraft:
7G--320
BC--737
JL--767 777 73H
NH--767 772 787 773 738
"FUK"->"PVG" with the following choice of airline and aircraft:
CA--320
MU--320 738
```  
Well, it's pretty clear what the output is saying. The landmarked output is similar to this one.  
The output shows departure and destinations your travel in chronical order and provides all airline and aircraft information.
