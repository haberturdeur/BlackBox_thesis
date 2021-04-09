bbConfig cfg;
cfg.ledMax = 100;
bbSetup(cfg);

bbCircle(Rgb(255,255,255));

bbLock();
sleep(1000);
if(bbRotationUp())
    bbUnlock();

bbShowDirection(North);