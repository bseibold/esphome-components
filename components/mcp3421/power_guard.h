#pragma once

#include "esphome/components/power_supply/power_supply.h"

class PowerGuard
{
public:
    explicit PowerGuard(::esphome::power_supply::PowerSupplyRequester& psr)
        : psr_(psr)
    {
        psr_.request();
    }

    ~PowerGuard()
    {
        psr_.unrequest();
    }

private:
    ::esphome::power_supply::PowerSupplyRequester& psr_;
};
