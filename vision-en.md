# BlackBox

## Idea:
### Library:
#### Overview:
* library to interface with all harware components either directly or indirectly
* 3 access modes:
    + direct access
        - provides direct access to all components separately,henceforth all calculations e.g. orientation has to be done by the user
    + access through interface
        - provides access to interface class which allows to hide all data from e.g. all position sensors into "1 value"
#### Structure:
* Manager
    + component classes (Rtc, accel, etc.)
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
* Locking
    + Latches
        - simple unlocking conditions e.g. time latch, location latch, slave latch (controlled from elsewhere)
    + Locks
        - sets of latches, all, or some latches have to be unlocked for the lock to unlock
        - lock a specific event callback from being called
    + Bariers
        - sets of latches, all, or some latches have to be unlocked for the lock to unlock
        - blocks any progress until unlocked
* Events
    + eventpp
        - dispatcher = synchronous events
    + lockable using locks
* Pages
    + Menus
        - 60 * (RGB + events(single click, double click, hold,...))
    + Apps
        - One purpose app (compass, combination lock)

#### Example

```cpp
tm start, end;

Page::PageManager pm;

Page::Sequences::Absolute sqA = {10, 20 , 5};
Page::Sequences::Relative sqR = {10, -5, 12 , -7};

Latch::Remote remoteLatch; // defakto by-default locked mutex
Latch::TimePeriod timeLatch(start, end);

Lock::All lock = {remoteLatch, timeLatch};

auto& mainPage = pm.newPage(Page::Empty, "main"); // tag
pm.newPage(Page::Empty, "secondary"); // tag
auto& link = pm.newPage(new Page::Sequence(sqA));
auto& link2 = pm.newPage(new Page::Sequence(sqR));
mainPage[15].link(link); // switch kontextu se vždy provede jako poslední event
mainPage[15].appendEvent(Events::Blink);
mainPage[15].lock(lock, INVERT);

mainPage[30].link(link2);
mainPage[30].lock(lock, NORMAL);

link.onSolve([&]{
    remoteLatch.unlock();
});

mainPage[45].link(pm["secondary"]);

pm.start();

```
---
