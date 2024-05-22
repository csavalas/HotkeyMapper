# HotkeyMapper

<img src="https://github.com/csavalas/HotkeyMapper/blob/main/screens/main.jpg?raw=true" alt="main" width="300"/>
Provides Vantage-like F12 customization options for the F9-F11 keys.

## Features
* Emulating a single key (eg. _Play/Pause_ key)
* Emulating full key sequences or combinations (eg. _hello world_, vs _CTRL + SHIFT + 9_)
* Opening any app (option to specify command line arguments for said app)
* Opening a URL
* Opening a file with its default association

## Installation
* Download Installer.zip from [here](https://github.com/csavalas/HotkeyMapper)
  * Unzip the downloaded Installer.zip file
* Run setup.bat to perform the following actions:
  * Copy HotkeyMapper.exe (frontend GUI) and HotKeyHelper.exe (Backend key emulator) to your local %APPDATA% folder
  * Create Start Menu links to for HotKeyMapper and the Uninstallataion batch file

## Usage
 * Run HotkeyMapper by clicking its shortcut in the Start Menu

## Various options
### Emulating a Key Sequence (_eg. 'hi!'_)
<img src="https://github.com/csavalas/HotkeyMapper/blob/main/screens/key1.jpg?raw=true" alt="key1" width="300"/> 

1. Select `Key Sequence` from the main window under the desired key section (`F9`-`F11`)
2. Select `H` from the dropdown menu, then click `Add key` 
    * Repeat step 2 for `i` and `!` 
3. `Steal Focus` 
    * Check this box if you do _NOT_ want the focused application to receive your key sequence
    * Uncheck this box if you _DO_ want the focused application to receive your key sequence
        * In this example (_hi!_), you would likely want to uncheck this box so the focused app receives the input (_eg. email client_)
4. Press the `Apply` key.

### Emulating a Key Combination (_eg. [CTRL] + [SHIFT] + 9_)
<img src="https://github.com/csavalas/HotkeyMapper/blob/main/screens/key1.jpg?raw=true" alt="key1" width="300"/> 

1. Select `Key Combination` from the main window under the desired key section (`F9`-`F11`)
2. Select `CTRL` from the dropdown menu, then click `Add key` 
    * Repeat step 2 for `SHIFT` and `9` 
3. `Steal Focus`
    * Check this box if you do _NOT_ want the focused application to receive your key sequence
        * In this example (_[CTRL] + [SHIFT] + 9_), you would likely want to check this box unless your key combo is specific to the focused app
    * Uncheck this box if you _DO_ want the focused application to receive your key sequence
4. Press the `Apply` key.

### Opening an app (_eg. chrome.exe --app=http://google.com_)
<img src="https://github.com/csavalas/HotkeyMapper/blob/main/screens/app.jpg?raw=true" alt="app" width="300"/> 

1. Select `Open App` from the main window under the desired key section (`F9`-`F11`)
2. Select `Browse` to navigate to and select your executable file, in this case `chrome.exe`
3. _Optional_ Enter in any command lin arguments for your app, in this example: `--app=http://google.com`
4. Press the `Apply` key.

### Opening a URL (_eg. https://ebaumsworld.com_)
<img src="https://github.com/csavalas/HotkeyMapper/blob/main/screens/url.jpg?raw=true" alt="app" width="300"/> 

1. Select `Open URL` from the main window under the desired key section (`F9`-`F11`)
2. Enter in the desired URL, in this case `https://ebaumsworld.com`
3. Press the `Apply` key.

### Opening a file (_eg. some_text_file.txt_)
<img src="https://github.com/csavalas/HotkeyMapper/blob/main/screens/file.jpg?raw=true" alt="app" width="300"/> 

1. Select `Open File` from the main window under the desired key section (`F9`-`F11`)
2. Select `Browse` to navigate to and select your file, in this case `some_text_file.txt`
3. Press the `Apply` key.

### Resetting to defaults

1. Select `Reset All to Default` from the main window
2. Press `Yes` in the confirmation dialog.
