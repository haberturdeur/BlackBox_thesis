pages.newPage("main");
pages.newApp(navigation, "navigation");
pages["main"][15].link(pages["navigation"]);
// Propoji navigaci na pozici 15 na hlavni strance
pages["main"][15].color(Rgb(0, 0, 255));
pages["navigation"].setHeading(15); // azimut 15 stupnu