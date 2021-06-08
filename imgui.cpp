#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "amemory.h"

int base = reinterpret_cast<int>(GetModuleHandleW(NULL));

void RenderMain();
{
    static bool enable_noclip = false;
    static bool enable_nospike = false;
    static bool enable_notransition = false;

    ImGui::Begin("Doki's Menu");
    ImGui::Text ("early ass beta");

    ImGui::Checkbox("NoClip", &enable_noclip)
    if(enable_noclip) amemory::write_bytes_protect(base + 0x20A23C, { 0xE9, 0x79, 0x06, 0x00, 0x00 });
    else amemory::write_bytes_protect(base + 0x20A23C, { 0x6A, 0x14, 0x8B, 0xCB, 0xFF });

    ImGui::Checkbox("NoSpike", &enable_nospike)
    if(enable_nospike) amemory::write_bytes_protect(base + 0x205347, { 0x75 });
    else amemory::write_bytes_protect(base + 0x20a23C, { 0x74 });

    ImGui::Checkbox("No Transition"), &enable_notransition
    if(enable_notransition) amemory::write_bytes_protect(base + 0xA5424, { 0x90, 0x90, 0x90, 0x90, 0x90 })
    else amemory::write_bytes_protect(base + 0xA5424, { 0xF3, 0x0F, 0x10, 0x45, 0x08 })
}