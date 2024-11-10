#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE
RGB_MATRIX_EFFECT(SOLID_REACTIVE)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static RGB SOLID_REACTIVE_math(HSV hsv, HSV hsvTarget, uint16_t offset) {
#            ifdef RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE
    hsv.h = scale16by8(g_rgb_timer, qadd8(rgb_matrix_config.speed, 8) >> 4);
#            endif

    RGB rgb = hsv_to_rgb(hsv);
    RGB rgbTarget = hsv_to_rgb(hsvTarget);
    RGB rgbCurrent;
    
    rgbCurrent.r = rgb.r + (((int16_t)offset * ((int16_t)rgbTarget.r - rgb.r)) >> 8);
    rgbCurrent.g = rgb.g + (((int16_t)offset * ((int16_t)rgbTarget.g - rgb.g)) >> 8);
    rgbCurrent.b = rgb.b + (((int16_t)offset * ((int16_t)rgbTarget.b - rgb.b)) >> 8);

    return rgbCurrent;
}

bool SOLID_REACTIVE(effect_params_t* params) {
    return effect_runner_solid_reactive(params, &SOLID_REACTIVE_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
