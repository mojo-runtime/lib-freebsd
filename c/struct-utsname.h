#pragma once

struct utsname
{
    char    sysname[32];
    char   nodename[32];
    char    release[32];
    char    version[32];
    char    machine[32];
    char domainname[32];
};
