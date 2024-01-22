void delay_millisec(unsigned ms )
{
    unsigned ticks = (ms * (SystemCoreClock/ 8)) / 1000 ;

    SysTick->LOAD = ticks;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;

    while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0);
    SysTick->CTRL = 0;
}