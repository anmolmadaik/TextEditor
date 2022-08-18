TEXT EDITOR
						~ github.com/anmolmadaik
1.	PURPOSE OF THE PROJECT
The purpose of this project is to build a text editor that automates the windows-based application. No commercial use of the application has been intended. This application was made using C++ and Qt 6.0.2 library. It contains the basic GUI and functionality of a text editor.

2.	BASIC FUNCTIONALITY:
The application contains 5 basic functionalities:

I.	FILE HANDING
To provide basic file manipulation. It contains following functionalities:
•	New: To create a completely new file
•	Open: To open an already saved file on the disk
•	Save: To save the changes made to a file which is already saved on the disk. If the file was not on the disk, it does the same function as the Save As option.
•	Save As: To select the path where the file needs to be saved.
•	Exit: To exit the application

II.	EDITING
Used to manipulate text entered in the editor. It contains following functionalities:
•	Undo: To reverse the previous action performed
•	Redo: To repeat the previous action undone
•	Cut: To remove the selected text from its position and move it to clipboard.
•	Copy: To copy the selected text to the clipboard without removing it from its position
•	Paste: Copies the text from the clipboard to the editor
•	Delete: To remove the selected text
•	Find: opens a dialog to find a specific letter, symbol, word or even phrase in the text editor. Additional options include to match the case of the needed text, and the direction of search relative to the present cursor position
•	Replace: opens a dialog to replace a letter, symbol, word or a phrase in the editor, if it exists, with some other letter, symbol, word or phrase.
•	Select All: To select the entire text in the editor.

III.	FORMATTING
•	Bold: Makes the text bold (increases font weight). 
•	Italic: Makes the text italic (gives slight slant to right).
•	Underline: Underlines the text (inserts a line under the text).
•	Strike: Strikes through the text (inserts a line through the text).
•	Color: Changes the color of the text.
•	Font: Opens font dialog with options to changes change font style, size and effects.
•	Line Wrap: If checked, breaks the text to the next line in case the text exceeds the viewable window.

IV.	VIEW
•	Zoom In: Increases the viewport of the current text by 5% at a time.
•	Zoom Out: Decreases the viewport of the current text by 5% at a time.
•	Restore Zoom: Changes the viewport to the original value
•	Toggle Theme: Toggles between the dark theme and the light theme

V.	HELP
•	Help: Opens the developer’s github profile
•	About: Shows basic information about the application and the developer

3.	REQUIREMENTS
This project is expected to run on all Windows platform that support Qt 6.0.2.
