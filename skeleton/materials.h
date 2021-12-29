#ifndef MATERIALS_H
#define MATERIALS_H

#include <vector>
#include <GL/gl.h>
#include "vertex.h"

namespace NewMaterialsAmbient
{
    GLfloat BLACK[] = {0.0f, 0.0f, 0.0f};
    GLfloat WHITE[] = {1.0f, 1.0f, 1.0f};
    GLfloat RED[] = {1.0f, 0.0f, 0.0f};
    GLfloat GREEN[] = {0.0f, 1.0f, 0.0f};
    GLfloat BLUE[] = {0.0f, 0.0f, 1.0f};
    GLfloat YELLOW[] = {1.0f, 1.0f, 0.0f};
    GLfloat CYAN[] = {0.0f, 1.0f, 1.0f};
    GLfloat MAGENTA[] = {1.0f, 0.0f, 1.0f};
    GLfloat GRAY[] = {0.5f, 0.5f, 0.5f};
    GLfloat DARK_GRAY[] = {0.25f, 0.25f, 0.25f};
    GLfloat LIGHT_GRAY[] = {0.75f, 0.75f, 0.75f};
    GLfloat ORANGE[] = {1.0f, 0.5f, 0.0f};
    GLfloat PINK[] = {1.0f, 0.0f, 0.5f};
    GLfloat PURPLE[] = {0.5f, 0.0f, 1.0f};
    GLfloat BROWN[] = {0.5f, 0.25f, 0.0f};
    GLfloat BEIGE[] = {0.75f, 0.75f, 0.5f};
    GLfloat LIME[] = {0.5f, 1.0f, 0.0f};
    GLfloat SEA_GREEN[] = {0.0f, 0.5f, 0.5f};
    GLfloat MAROON[] = {0.5f, 0.0f, 0.0f};
    GLfloat OLIVE[] = {0.5f, 0.5f, 0.0f};
    GLfloat NAVY[] = {0.0f, 0.0f, 0.5f};
    GLfloat TEAL[] = {0.0f, 0.5f, 0.5f};
   
    GLfloat EMERALD[] = {0.0215f, 0.1745f, 0.0215f};
    GLfloat JADE[] = {0.135f, 0.2225f, 0.1575f};
    GLfloat OBSIDIAN[] = {0.05375f, 0.05f, 0.06625f};
    GLfloat PEARL[] = {0.25f, 0.20725f, 0.20725f};
    GLfloat RUBY[] = {0.1745f, 0.01175f, 0.01175f};
    GLfloat TURQUOISE[] = {0.1f, 0.18725f, 0.1745f};
    GLfloat BRASS[] = {0.329412f, 0.223529f, 0.027451f};
    GLfloat BRONZE[] = {0.2125f, 0.1275f, 0.054f};
    GLfloat CHROME[] = {0.25f, 0.25f, 0.25f};
    GLfloat COPPER[] = {0.19125f, 0.0735f, 0.0225f};
    GLfloat GOLD[] = {0.24725f, 0.1995f, 0.0745f};
    GLfloat SILVER[] = {0.19225f, 0.19225f, 0.19225f};
    GLfloat BLACK_PLASTIC[] = {0.0f, 0.0f, 0.0f};
    GLfloat CYAN_PLASTIC[] = {0.0f, 0.1f, 0.06f};
    GLfloat GREEN_PLASTIC[] = {0.0f, 0.0f, 0.0f};
    GLfloat RED_PLASTIC[] = {0.0f, 0.0f, 0.0f};
    GLfloat WHITE_PLASTIC[] = {0.55f, 0.55f, 0.55f};
    GLfloat YELLOW_PLASTIC[] = {0.0f, 0.0f, 0.0f};
    GLfloat BLACK_RUBBER[] = {0.02f, 0.02f, 0.02f};

} // namespace NewMaterials

namespace NewMaterialsDiffuse
{
    GLfloat BLACK[] = {0.0f, 0.0f, 0.0f};
    GLfloat WHITE[] = {1.0f, 1.0f, 1.0f};
    GLfloat RED[] = {1.0f, 0.0f, 0.0f};
    GLfloat GREEN[] = {0.0f, 1.0f, 0.0f};
    GLfloat BLUE[] = {0.0f, 0.0f, 1.0f};
    GLfloat YELLOW[] = {1.0f, 1.0f, 0.0f};
    GLfloat CYAN[] = {0.0f, 1.0f, 1.0f};
    GLfloat MAGENTA[] = {1.0f, 0.0f, 1.0f};
    GLfloat GRAY[] = {0.5f, 0.5f, 0.5f};
    GLfloat DARK_GRAY[] = {0.25f, 0.25f, 0.25f};
    GLfloat LIGHT_GRAY[] = {0.75f, 0.75f, 0.75f};
    GLfloat ORANGE[] = {1.0f, 0.5f, 0.0f};
    GLfloat PINK[] = {1.0f, 0.0f, 0.5f};
    GLfloat PURPLE[] = {0.5f, 0.0f, 1.0f};
    GLfloat BROWN[] = {0.5f, 0.25f, 0.0f};
    GLfloat BEIGE[] = {0.75f, 0.75f, 0.5f};
    GLfloat LIME[] = {0.5f, 1.0f, 0.0f};
    GLfloat SEA_GREEN[] = {0.0f, 0.5f, 0.5f};
    GLfloat MAROON[] = {0.5f, 0.0f, 0.0f};
    GLfloat OLIVE[] = {0.5f, 0.5f, 0.0f};
    GLfloat NAVY[] = {0.0f, 0.0f, 0.5f};
    GLfloat TEAL[] = {0.0f, 0.5f, 0.5f};

    GLfloat EMERALD[] = {0.07568f, 0.61424f, 0.07568f};
    GLfloat JADE[] = {0.54f, 0.89f, 0.63f};
    GLfloat OBSIDIAN[] = {0.18275f, 0.17f, 0.22525f};
    GLfloat PEARL[] = {1.0f, 0.829f, 0.829f};
    GLfloat RUBY[] = {0.61424f, 0.04136f, 0.04136f};
    GLfloat TURQUOISE[] = {0.396f, 0.74151f, 0.69102f};
    GLfloat BRASS[] = {0.780392f, 0.568627f, 0.113725f};
    GLfloat BRONZE[] = {0.714f, 0.4284f, 0.18144f};
    GLfloat CHROME[] = {0.4f, 0.4f, 0.4f};
    GLfloat COPPER[] = {0.7038f, 0.27048f, 0.0828f};
    GLfloat GOLD[] = {0.75164f, 0.60648f, 0.22648f};
    GLfloat SILVER[] = {0.50754f, 0.50754f, 0.50754f};
    GLfloat BLACK_PLASTIC[] = {0.0f, 0.0f, 0.0f};
    GLfloat CYAN_PLASTIC[] = {0.0f, 0.50980f, 0.50980f};
    GLfloat GREEN_PLASTIC[] = {0.1f, 0.35f, 0.1f};
    GLfloat RED_PLASTIC[] = {0.5f, 0.0f, 0.0f};
    GLfloat WHITE_PLASTIC[] = {0.55f, 0.55f, 0.55f};
    GLfloat YELLOW_PLASTIC[] = {0.5f, 0.5f, 0.0f};
    GLfloat BLACK_RUBBER[] = {0.02f, 0.02f, 0.02f};
} // namespace NewMaterialsDiffuse

namespace NewMaterialsSpecular
{
    GLfloat BLACK[] = {0.0f, 0.0f, 0.0f};
    GLfloat WHITE[] = {1.0f, 1.0f, 1.0f};
    GLfloat RED[] = {1.0f, 0.0f, 0.0f};
    GLfloat GREEN[] = {0.0f, 1.0f, 0.0f};
    GLfloat BLUE[] = {0.0f, 0.0f, 1.0f};
    GLfloat YELLOW[] = {1.0f, 1.0f, 0.0f};
    GLfloat CYAN[] = {0.0f, 1.0f, 1.0f};
    GLfloat MAGENTA[] = {1.0f, 0.0f, 1.0f};
    GLfloat GRAY[] = {0.5f, 0.5f, 0.5f};
    GLfloat DARK_GRAY[] = {0.25f, 0.25f, 0.25f};
    GLfloat LIGHT_GRAY[] = {0.75f, 0.75f, 0.75f};
    GLfloat ORANGE[] = {1.0f, 0.5f, 0.0f};
    GLfloat PINK[] = {1.0f, 0.0f, 0.5f};
    GLfloat PURPLE[] = {0.5f, 0.0f, 1.0f};
    GLfloat BROWN[] = {0.5f, 0.25f, 0.0f};
    GLfloat BEIGE[] = {0.75f, 0.75f, 0.5f};
    GLfloat LIME[] = {0.5f, 1.0f, 0.0f};
    GLfloat SEA_GREEN[] = {0.0f, 0.5f, 0.5f};
    GLfloat MAROON[] = {0.5f, 0.0f, 0.0f};
    GLfloat OLIVE[] = {0.5f, 0.5f, 0.0f};
    GLfloat NAVY[] = {0.0f, 0.0f, 0.5f};
    GLfloat TEAL[] = {0.0f, 0.5f, 0.5f};

    GLfloat EMERAL[] = {0.633f, 0.727811f, 0.633f};
    GLfloat JADE[] = {0.316228f, 0.316228f, 0.316228f};
    GLfloat OBSIDIAN[] = {0.332741f, 0.328634f, 0.346435f};
    GLfloat PEARL[] = {0.296648f, 0.296648f, 0.296648f};
    GLfloat RUBY[] = {0.727811f, 0.626959f, 0.626959f};    
    GLfloat TURQUOISE[] = {0.297254f, 0.30829f, 0.306678f};
    GLfloat BRASS[] = {0.992157f, 0.941176f, 0.807843f};
    GLfloat BRONZE[] = {0.714f, 0.4284f, 0.18144f};
    GLfloat CHROME[] = {0.4f, 0.4f, 0.4f};
    GLfloat COPPER[] = {0.7038f, 0.27048f, 0.0828f};
    GLfloat GOLD[] = {0.75164f, 0.60648f, 0.22648f};
    GLfloat SILVER[] = {0.50754f, 0.50754f, 0.50754f};
    GLfloat BLACK_PLASTIC[] = {0.0f, 0.0f, 0.0f};
    GLfloat CYAN_PLASTIC[] = {0.0f, 0.50980f, 0.50980f};
    GLfloat GREEN_PLASTIC[] = {0.1f, 0.35f, 0.1f};
    GLfloat RED_PLASTIC[] = {0.5f, 0.0f, 0.0f};
    GLfloat WHITE_PLASTIC[] = {0.55f, 0.55f, 0.55f};
    GLfloat YELLOW_PLASTIC[] = {0.5f, 0.5f, 0.0f};
    GLfloat BLACK_RUBBER[] = {0.02f, 0.02f, 0.02f};

} // namespace NewMaterialsSpecular

namespace NewMaterialsShininess
{
    GLfloat BLACK[] = {0.0f, 0.0f, 0.0f};
    GLfloat WHITE[] = {1.0f, 1.0f, 1.0f};
    GLfloat RED[] = {1.0f, 0.0f, 0.0f};
    GLfloat GREEN[] = {0.0f, 1.0f, 0.0f};
    GLfloat BLUE[] = {0.0f, 0.0f, 1.0f};
    GLfloat YELLOW[] = {1.0f, 1.0f, 0.0f};
    GLfloat CYAN[] = {0.0f, 1.0f, 1.0f};
    GLfloat MAGENTA[] = {1.0f, 0.0f, 1.0f};
    GLfloat GRAY[] = {0.5f, 0.5f, 0.5f};
    GLfloat DARK_GRAY[] = {0.25f, 0.25f, 0.25f};
    GLfloat LIGHT_GRAY[] = {0.75f, 0.75f, 0.75f};
    GLfloat ORANGE[] = {1.0f, 0.5f, 0.0f};
    GLfloat PINK[] = {1.0f, 0.0f, 0.5f};
    GLfloat PURPLE[] = {0.5f, 0.0f, 1.0f};
    GLfloat BROWN[] = {0.5f, 0.25f, 0.0f};
    GLfloat BEIGE[] = {0.75f, 0.75f, 0.5f};
    GLfloat LIME[] = {0.5f, 1.0f, 0.0f};
    GLfloat SEA_GREEN[] = {0.0f, 0.5f, 0.5f};
    GLfloat MAROON[] = {0.5f, 0.0f, 0.0f};
    GLfloat OLIVE[] = {0.5f, 0.5f, 0.0f};
    GLfloat NAVY[] = {0.0f, 0.0f, 0.5f};
    GLfloat TEAL[] = {0.0f, 0.5f, 0.5f};

    GLfloat EMERALD = {0.6f};
    GLfloat JADE = {0.1f};
    GLfloat OBSIDIAN = {0.3f};
    GLfloat PEARL = {0.9f};
    GLfloat RUBY = {0.7f};
    GLfloat TURQUOISE = {0.5f};
    GLfloat BRASS = {0.3f};
    GLfloat BRONZE = {0.2f};
    GLfloat CHROME = {0.4f};
    GLfloat COPPER = {0.1f};
    GLfloat GOLD = {0.1f};
    GLfloat SILVER = {0.2f};
    GLfloat BLACK_PLASTIC = {0.0f};
    GLfloat CYAN_PLASTIC = {0.0f};
    GLfloat GREEN_PLASTIC = {0.0f};
    GLfloat RED_PLASTIC = {0.0f};
    GLfloat WHITE_PLASTIC = {0.0f};
    GLfloat YELLOW_PLASTIC = {0.0f};
    GLfloat BLACK_RUBBER = {0.0f};
}

#endif