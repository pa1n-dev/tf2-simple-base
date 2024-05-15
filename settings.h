#pragma once

namespace globals
{
    inline bool unload = false;
    inline D3DMATRIX world_to_projection;
}

namespace settings
{
    namespace visuals
    {
        inline bool enable = false;
        inline bool box = false;
        inline bool name = false;

        namespace colors
        {
            inline float box[4] = { 1.f, 1.f, 1.f, 1.f };
            inline float name[4] = { 1.f, 1.f, 1.f, 1.f };
        }
    }
}