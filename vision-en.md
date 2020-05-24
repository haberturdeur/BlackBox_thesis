# BlackBox

## Idea:
### Library:
#### Overview:
* 3 modes:
    + direct access
        - provides direct access to all components
    + access through interface
        - provides access to interface class which allows to hide all data from e.g. all position sensors into "1 value"
        - pages ?
            - menu styled interface for LEDRing and RE (RotaryEncoder)
            - each page contains color scheme and 60 callbacks capable of referencing and switching to other pages
                - possible optional use of "button/variable" instead of callback
    + event based access
        - provides the interface with addition of registration of callback functions for different events that may occur
        - events are considered to be the main driving element
        - ESP-IDF event / Free RTOS queue ? 

#### Structure:
* Manager
    + component classes (Rtc, accel, etc.)
    + event handling class
    + interface
        - page handling class ?
---
### Engine:
#### Overview:
* build on top of library
* allows for easier implementation of games
* removes interfacing with hardware itself
    + only contais necessary functions such as lock(), unlock() etc.
* fully event driven
* "lock" classes
    + different types of "puzzles" e.g. time gate, location(GPS), orientation, password, more complex puzzles

#### Structure
<!-- FIXME: put structure here --> 
---

## To solve:
* Will low level access mess with high level access? Probably yes.
    + How do I fix this?
        - Only allow access to one level at a time.
        - Using and "redirecting" aliases. 
        - Don't care, let users deal with it.
        - Something else?
