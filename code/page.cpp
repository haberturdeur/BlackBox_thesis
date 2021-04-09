tm start, end;

Page::PageManager pm;

Page::Sequences::Absolute sqA = {10, 20 , 5};
Page::Sequences::Relative sqR = {10, -5, 12 , -7};

Latch::Remote remoteLatch;
Latch::TimePeriod timeLatch(start, end);

Lock::All lock = {remoteLatch, timeLatch};

auto& mainPage = pm.newPage(Page::Empty, "main"); // tag
pm.newPage(Page::Empty, "secondary"); // tag
auto& link = pm.newApp(sqA);
auto& link2 = pm.newApp(sqR);
mainPage[15].link(link); // switch kontextu se vzdy provede jako posledni event
mainPage[15].appendEvent(Events::Blink);
mainPage[15].lock(lock, INVERT);

mainPage[30].link(link2);
mainPage[30].lock(lock, NORMAL);

link.onSolve([&]{
    remoteLatch.unlock();
});

mainPage[45].link(pm["secondary"]);

pm.start();