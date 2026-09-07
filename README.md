# Simple Line Editor in C

## About the Project

This project is a simple command-line line editor developed in C.

It allows users to create, view and modify a small text document using commands from the terminal.

## Team Members

1. Preksha MV
2. Olivia Mukherjee
3. Nabiya Khan

## Data Structure

We use an **array of strings** to store the lines of the document.

```text
char *lines[100]
```

The variable `lineCount` stores the current number of lines.

An array of strings was chosen because the document is small and it provides simple access to individual lines. Insertion and deletion are handled by shifting the existing lines.

## Features Implemented

### Core Features

* Insert a line
* Delete a line
* Display the document

### Additional Features

* Save document to a `.txt` file
* Load document from a `.txt` file
* Search for a word or phrase
* Help command
* Exit command

## Commands

| Command   | Description                   |
| --------- | ----------------------------- |
| `insert`  | Inserts a new line            |
| `delete`  | Deletes a line                |
| `display` | Displays the document         |
| `save`    | Saves the document to a file  |
| `load`    | Loads a document from a file  |
| `search`  | Searches for a word or phrase |
| `help`    | Displays available commands   |
| `exit`    | Exits the editor              |

## Requirements

* C compiler
* GCC
* Command-line terminal

## Compilation

Open the terminal in the project folder and run:

```bash
gcc line_editor.c -o line_editor.exe
```

## Running the Program

On Windows:

```powershell
.\line_editor.exe
```

## Example

```text
=================================
       SIMPLE LINE EDITOR
=================================
Type 'help' to see available commands.

> insert
Enter line number to insert: 1
Enter text: Hello
Line inserted successfully.

> display

----- DOCUMENT -----
1. Hello
--------------------
```

## Project Files

```text
line-editor/
│
├── line_editor.c
├── HELP.md
├── README.md
└── notes.txt
```

## Conclusion

The project demonstrates basic text editing operations using C, arrays of strings, dynamic memory allocation, string handling and file handling.
