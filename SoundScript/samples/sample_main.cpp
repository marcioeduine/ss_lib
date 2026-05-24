#include "Sample.hpp"

int main(void)
{
    try
    {
        Sample("snare").save();
        Sample("kick").save();
        Sample("drum").save();
        Sample("clap").save();
        Sample("hat").save();
    }
    catch (const std::exception &e)
    {
        std::cerr << "[ SAMPLE ERROR ] " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

