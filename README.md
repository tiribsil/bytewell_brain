If you're using a different OS, the source code is in the "src" folder.

For testing on a PC:
- Draw the digit.
- Run "preprocess.exe path\to\drawing.png | test.exe"

For testing on an Arduino board:
- Draw the digit.
- Run "preprocess.exe path\to\drawing.png", the bitmap will be copied into the clipboard.
- Paste the bitmap into the input array in the arduino sketch.
- Upload the updated code to the board.
