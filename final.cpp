#include <iostream> // for the input/output
#include <stdlib.h> // for the getenv call
#include <sys/sysinfo.h> // for the system uptime call
#include <cgicc/Cgicc.h> // the cgicc headers
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include <unistd.h>

#include "GPIO.h"
#include "AnalogIn.h"

#define LED_GPIO "/sys/class/gpio/gpio60/"


using namespace exploringBB;
using namespace std;


float getResistance(int adc_value) {
float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
// Top resistance is 10000.0 Ohms.
float resistance = (cur_voltage *10000.0f) / (1.80f - cur_voltage);
return resistance;
}

void writeGPIO(string filename, string value){
 fstream fs;
 string path(LED_GPIO);
 fs.open((path + filename).c_str(), fstream::out);
 fs << value;
 fs.close();
}


int main(){
 AnalogIn AIN0(0);
 int state;
 AnalogIn AIN6(6);

 GPIO inGPIO(46);
 inGPIO.setDirection(INPUT);
 float resistance = getResistance(AIN0.readADCsample());
 
 // Read the file "value" in gpoio46 folder.
 state = inGPIO.getValue();
 if(state == 0)
 cout << "Button Pressed" << endl;
 cout << "The Resistance is: " << resistance << "K Ohms" << endl; 
 cout << "Blinking LED Two Times" << endl;
 
 writeGPIO("value", "0");
 sleep(1);
 writeGPIO("value", "1");
 sleep(1);
 writeGPIO("value", "0");
 sleep(1);
 writeGPIO("value", "1");
 sleep(1);

 if (state == 1) 
 cout << "Button Not Pressed" << endl;
 cout << "The Temperature is: " << AIN6.readADCsample() << endl;

}
