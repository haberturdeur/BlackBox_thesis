void app_main(){
    gpio_config_t io_conf;

    //disable interrupt
    io_conf.intr_type = GPIO_INTR_DISABLE;

    //set as output mode
    io_conf.mode = GPIO_MODE_OUTPUT;

    //bit mask of the pins that you want to set,e.g.GPIO18/19
    io_conf.pin_bit_mask = (1ULL<<GPIO_NUM_18);

    //disable pull-down mode
    io_conf.pull_down_en = 0;

    //disable pull-up mode
    io_conf.pull_up_en = 0;

    //configure GPIO with the given settings
    gpio_config(&io_conf);

    for (int i = 0; true; i++)
    {
        printf("state: %d\n", i%2);
        gpio_set_level(GPIO_NUM_18, i % 2);
        vTaskDelay(1000 / portTICK_RATE_MS);
    }
}