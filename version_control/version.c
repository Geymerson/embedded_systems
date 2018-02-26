#include <stdint.h>
#include <stdio.h>

#ifdef DEBUG
#define VersionPrint() printf("Version: %d.%d.%d\n", __version.major, __version.minor, __version.build)
#else
#define VersionPrint()
#endif

static struct {
    uint8_t major;
    uint8_t minor;
    uint16_t build;
} __version;

void VersionInit() {
    __version.major = MAJOR;
    __version.minor = MINOR;
    __version.build = BUILD;
}

void VersionIncBuild() {
    __version.build++;
}

int main() {
    VersionInit();
    VersionPrint();
    VersionIncBuild();
    VersionPrint();
}
