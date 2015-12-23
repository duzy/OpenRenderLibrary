/*******************************************************************************
 *  ORL 0.00 - https://github.com/duzy/ORL
 *  Open Render Library, a library for rendering 3D models.
 *------------------------------------------------------------------------------
 *  Copyright (c) 2015 Duzy Chan <code@duzy.info>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *  
 */
#ifndef __ORL_INTERNAL_DRIVER_HPP__
#define __ORL_INTERNAL_DRIVER_HPP__ 1
#include "ORL/Shader.hpp"

namespace ORL
{
  class Driver : Noncopyable
  {
    Driver();
    virtual ~Driver();

  public:
    static const Driver & get();

    enum Enum_2_0 {
      DEPTH_BUFFER_BIT               = 0x00000100,
      STENCIL_BUFFER_BIT             = 0x00000400,
      COLOR_BUFFER_BIT               = 0x00004000,
      FALSE                          = 0,
      TRUE                           = 1,
      POINTS                         = 0x0000,
      LINES                          = 0x0001,
      LINE_LOOP                      = 0x0002,
      LINE_STRIP                     = 0x0003,
      TRIANGLES                      = 0x0004,
      TRIANGLE_STRIP                 = 0x0005,
      TRIANGLE_FAN                   = 0x0006,
      ZERO                           = 0,
      ONE                            = 1,
      SRC_COLOR                      = 0x0300,
      ONE_MINUS_SRC_COLOR            = 0x0301,
      SRC_ALPHA                      = 0x0302,
      ONE_MINUS_SRC_ALPHA            = 0x0303,
      DST_ALPHA                      = 0x0304,
      ONE_MINUS_DST_ALPHA            = 0x0305,
      DST_COLOR                      = 0x0306,
      ONE_MINUS_DST_COLOR            = 0x0307,
      SRC_ALPHA_SATURATE             = 0x0308,
      FUNC_ADD                       = 0x8006,
      BLEND_EQUATION                 = 0x8009,
      BLEND_EQUATION_RGB             = 0x8009,
      BLEND_EQUATION_ALPHA           = 0x883D,
      FUNC_SUBTRACT                  = 0x800A,
      FUNC_REVERSE_SUBTRACT          = 0x800B,
      BLEND_DST_RGB                  = 0x80C8,
      BLEND_SRC_RGB                  = 0x80C9,
      BLEND_DST_ALPHA                = 0x80CA,
      BLEND_SRC_ALPHA                = 0x80CB,
      CONSTANT_COLOR                 = 0x8001,
      ONE_MINUS_CONSTANT_COLOR       = 0x8002,
      CONSTANT_ALPHA                 = 0x8003,
      ONE_MINUS_CONSTANT_ALPHA       = 0x8004,
      BLEND_COLOR                    = 0x8005,
      ARRAY_BUFFER                   = 0x8892,
      ELEMENT_ARRAY_BUFFER           = 0x8893,
      ARRAY_BUFFER_BINDING           = 0x8894,
      ELEMENT_ARRAY_BUFFER_BINDING   = 0x8895,
      STREAM_DRAW                    = 0x88E0,
      STATIC_DRAW                    = 0x88E4,
      DYNAMIC_DRAW                   = 0x88E8,
      BUFFER_SIZE                    = 0x8764,
      BUFFER_USAGE                   = 0x8765,
      CURRENT_VERTEX_ATTRIB          = 0x8626,
      FRONT                          = 0x0404,
      BACK                           = 0x0405,
      FRONT_AND_BACK                 = 0x0408,
      TEXTURE_2D                     = 0x0DE1,
      CULL_FACE                      = 0x0B44,
      BLEND                          = 0x0BE2,
      DITHER                         = 0x0BD0,
      STENCIL_TEST                   = 0x0B90,
      DEPTH_TEST                     = 0x0B71,
      SCISSOR_TEST                   = 0x0C11,
      POLYGON_OFFSET_FILL            = 0x8037,
      SAMPLE_ALPHA_TO_COVERAGE       = 0x809E,
      SAMPLE_COVERAGE                = 0x80A0,
      NO_ERROR                       = 0,
      INVALID_ENUM                   = 0x0500,
      INVALID_VALUE                  = 0x0501,
      INVALID_OPERATION              = 0x0502,
      OUT_OF_MEMORY                  = 0x0505,
      CW                             = 0x0900,
      CCW                            = 0x0901,
      LINE_WIDTH                     = 0x0B21,
      ALIASED_POINT_SIZE_RANGE       = 0x846D,
      ALIASED_LINE_WIDTH_RANGE       = 0x846E,
      CULL_FACE_MODE                 = 0x0B45,
      FRONT_FACE                     = 0x0B46,
      DEPTH_RANGE                    = 0x0B70,
      DEPTH_WRITEMASK                = 0x0B72,
      DEPTH_CLEAR_VALUE              = 0x0B73,
      DEPTH_FUNC                     = 0x0B74,
      STENCIL_CLEAR_VALUE            = 0x0B91,
      STENCIL_FUNC                   = 0x0B92,
      STENCIL_FAIL                   = 0x0B94,
      STENCIL_PASS_DEPTH_FAIL        = 0x0B95,
      STENCIL_PASS_DEPTH_PASS        = 0x0B96,
      STENCIL_REF                    = 0x0B97,
      STENCIL_VALUE_MASK             = 0x0B93,
      STENCIL_WRITEMASK              = 0x0B98,
      STENCIL_BACK_FUNC              = 0x8800,
      STENCIL_BACK_FAIL              = 0x8801,
      STENCIL_BACK_PASS_DEPTH_FAIL   = 0x8802,
      STENCIL_BACK_PASS_DEPTH_PASS   = 0x8803,
      STENCIL_BACK_REF               = 0x8CA3,
      STENCIL_BACK_VALUE_MASK        = 0x8CA4,
      STENCIL_BACK_WRITEMASK         = 0x8CA5,
      VIEWPORT                       = 0x0BA2,
      SCISSOR_BOX                    = 0x0C10,
      COLOR_CLEAR_VALUE              = 0x0C22,
      COLOR_WRITEMASK                = 0x0C23,
      UNPACK_ALIGNMENT               = 0x0CF5,
      PACK_ALIGNMENT                 = 0x0D05,
      MAX_TEXTURE_SIZE               = 0x0D33,
      MAX_VIEWPORT_DIMS              = 0x0D3A,
      SUBPIXEL_BITS                  = 0x0D50,
      RED_BITS                       = 0x0D52,
      GREEN_BITS                     = 0x0D53,
      BLUE_BITS                      = 0x0D54,
      ALPHA_BITS                     = 0x0D55,
      DEPTH_BITS                     = 0x0D56,
      STENCIL_BITS                   = 0x0D57,
      POLYGON_OFFSET_UNITS           = 0x2A00,
      POLYGON_OFFSET_FACTOR          = 0x8038,
      TEXTURE_BINDING_2D             = 0x8069,
      SAMPLE_BUFFERS                 = 0x80A8,
      SAMPLES                        = 0x80A9,
      SAMPLE_COVERAGE_VALUE          = 0x80AA,
      SAMPLE_COVERAGE_INVERT         = 0x80AB,
      NUM_COMPRESSED_TEXTURE_FORMATS = 0x86A2,
      COMPRESSED_TEXTURE_FORMATS     = 0x86A3,
      DONT_CARE                      = 0x1100,
      FASTEST                        = 0x1101,
      NICEST                         = 0x1102,
      GENERATE_MIPMAP_HINT           = 0x8192,
      BYTE                           = 0x1400,
      UNSIGNED_BYTE                  = 0x1401,
      SHORT                          = 0x1402,
      UNSIGNED_SHORT                 = 0x1403,
      INT                            = 0x1404,
      UNSIGNED_INT                   = 0x1405,
      FLOAT                          = 0x1406,
      FIXED                          = 0x140C,
      DEPTH_COMPONENT                = 0x1902,
      ALPHA                          = 0x1906,
      RGB                            = 0x1907,
      RGBA                           = 0x1908,
      LUMINANCE                      = 0x1909,
      LUMINANCE_ALPHA                = 0x190A,
      UNSIGNED_SHORT_4_4_4_4         = 0x8033,
      UNSIGNED_SHORT_5_5_5_1         = 0x8034,
      UNSIGNED_SHORT_5_6_5           = 0x8363,
      FRAGMENT_SHADER                = 0x8B30,
      VERTEX_SHADER                  = 0x8B31,
      MAX_VERTEX_ATTRIBS             = 0x8869,
      MAX_VERTEX_UNIFORM_VECTORS     = 0x8DFB,
      MAX_VARYING_VECTORS            = 0x8DFC,
      MAX_COMBINED_TEXTURE_IMAGE_UNITS = 0x8B4D,
      MAX_VERTEX_TEXTURE_IMAGE_UNITS = 0x8B4C,
      MAX_TEXTURE_IMAGE_UNITS        = 0x8872,
      MAX_FRAGMENT_UNIFORM_VECTORS   = 0x8DFD,
      SHADER_TYPE                    = 0x8B4F,
      DELETE_STATUS                  = 0x8B80,
      LINK_STATUS                    = 0x8B82,
      VALIDATE_STATUS                = 0x8B83,
      ATTACHED_SHADERS               = 0x8B85,
      ACTIVE_UNIFORMS                = 0x8B86,
      ACTIVE_UNIFORM_MAX_LENGTH      = 0x8B87,
      ACTIVE_ATTRIBUTES              = 0x8B89,
      ACTIVE_ATTRIBUTE_MAX_LENGTH    = 0x8B8A,
      SHADING_LANGUAGE_VERSION       = 0x8B8C,
      CURRENT_PROGRAM                = 0x8B8D,
      NEVER                          = 0x0200,
      LESS                           = 0x0201,
      EQUAL                          = 0x0202,
      LEQUAL                         = 0x0203,
      GREATER                        = 0x0204,
      NOTEQUAL                       = 0x0205,
      GEQUAL                         = 0x0206,
      ALWAYS                         = 0x0207,
      KEEP                           = 0x1E00,
      REPLACE                        = 0x1E01,
      INCR                           = 0x1E02,
      DECR                           = 0x1E03,
      INVERT                         = 0x150A,
      INCR_WRAP                      = 0x8507,
      DECR_WRAP                      = 0x8508,
      VENDOR                         = 0x1F00,
      RENDERER                       = 0x1F01,
      VERSION                        = 0x1F02,
      EXTENSIONS                     = 0x1F03,
      NEAREST                        = 0x2600,
      LINEAR                         = 0x2601,
      NEAREST_MIPMAP_NEAREST         = 0x2700,
      LINEAR_MIPMAP_NEAREST          = 0x2701,
      NEAREST_MIPMAP_LINEAR          = 0x2702,
      LINEAR_MIPMAP_LINEAR           = 0x2703,
      TEXTURE_MAG_FILTER             = 0x2800,
      TEXTURE_MIN_FILTER             = 0x2801,
      TEXTURE_WRAP_S                 = 0x2802,
      TEXTURE_WRAP_T                 = 0x2803,
      TEXTURE                        = 0x1702,
      TEXTURE_CUBE_MAP               = 0x8513,
      TEXTURE_BINDING_CUBE_MAP       = 0x8514,
      TEXTURE_CUBE_MAP_POSITIVE_X    = 0x8515,
      TEXTURE_CUBE_MAP_NEGATIVE_X    = 0x8516,
      TEXTURE_CUBE_MAP_POSITIVE_Y    = 0x8517,
      TEXTURE_CUBE_MAP_NEGATIVE_Y    = 0x8518,
      TEXTURE_CUBE_MAP_POSITIVE_Z    = 0x8519,
      TEXTURE_CUBE_MAP_NEGATIVE_Z    = 0x851A,
      MAX_CUBE_MAP_TEXTURE_SIZE      = 0x851C,
      /*
      TEXTURE0                       = 0x84C0,
      TEXTURE1                       = 0x84C1,
      TEXTURE2                       = 0x84C2,
      TEXTURE3                       = 0x84C3,
      TEXTURE4                       = 0x84C4,
      TEXTURE5                       = 0x84C5,
      TEXTURE6                       = 0x84C6,
      TEXTURE7                       = 0x84C7,
      TEXTURE8                       = 0x84C8,
      TEXTURE9                       = 0x84C9,
      TEXTURE10                      = 0x84CA,
      TEXTURE11                      = 0x84CB,
      TEXTURE12                      = 0x84CC,
      TEXTURE13                      = 0x84CD,
      TEXTURE14                      = 0x84CE,
      TEXTURE15                      = 0x84CF,
      TEXTURE16                      = 0x84D0,
      TEXTURE17                      = 0x84D1,
      TEXTURE18                      = 0x84D2,
      TEXTURE19                      = 0x84D3,
      TEXTURE20                      = 0x84D4,
      TEXTURE21                      = 0x84D5,
      TEXTURE22                      = 0x84D6,
      TEXTURE23                      = 0x84D7,
      TEXTURE24                      = 0x84D8,
      TEXTURE25                      = 0x84D9,
      TEXTURE26                      = 0x84DA,
      TEXTURE27                      = 0x84DB,
      TEXTURE28                      = 0x84DC,
      TEXTURE29                      = 0x84DD,
      TEXTURE30                      = 0x84DE,
      TEXTURE31                      = 0x84DF,
      */
      ACTIVE_TEXTURE                 = 0x84E0,
      REPEAT                         = 0x2901,
      CLAMP_TO_EDGE                  = 0x812F,
      MIRRORED_REPEAT                = 0x8370,
      FLOAT_VEC2                     = 0x8B50,
      FLOAT_VEC3                     = 0x8B51,
      FLOAT_VEC4                     = 0x8B52,
      INT_VEC2                       = 0x8B53,
      INT_VEC3                       = 0x8B54,
      INT_VEC4                       = 0x8B55,
      BOOL                           = 0x8B56,
      BOOL_VEC2                      = 0x8B57,
      BOOL_VEC3                      = 0x8B58,
      BOOL_VEC4                      = 0x8B59,
      FLOAT_MAT2                     = 0x8B5A,
      FLOAT_MAT3                     = 0x8B5B,
      FLOAT_MAT4                     = 0x8B5C,
      SAMPLER_2D                     = 0x8B5E,
      SAMPLER_CUBE                   = 0x8B60,
      VERTEX_ATTRIB_ARRAY_ENABLED    = 0x8622,
      VERTEX_ATTRIB_ARRAY_SIZE       = 0x8623,
      VERTEX_ATTRIB_ARRAY_STRIDE     = 0x8624,
      VERTEX_ATTRIB_ARRAY_TYPE       = 0x8625,
      VERTEX_ATTRIB_ARRAY_NORMALIZED = 0x886A,
      VERTEX_ATTRIB_ARRAY_POINTER    = 0x8645,
      VERTEX_ATTRIB_ARRAY_BUFFER_BINDING = 0x889F,
      IMPLEMENTATION_COLOR_READ_TYPE = 0x8B9A,
      IMPLEMENTATION_COLOR_READ_FORMAT = 0x8B9B,
      COMPILE_STATUS                 = 0x8B81,
      INFO_LOG_LENGTH                = 0x8B84,
      SHADER_SOURCE_LENGTH           = 0x8B88,
      SHADER_COMPILER                = 0x8DFA,
      SHADER_BINARY_FORMATS          = 0x8DF8,
      NUM_SHADER_BINARY_FORMATS      = 0x8DF9,
      LOW_FLOAT                      = 0x8DF0,
      MEDIUM_FLOAT                   = 0x8DF1,
      HIGH_FLOAT                     = 0x8DF2,
      LOW_INT                        = 0x8DF3,
      MEDIUM_INT                     = 0x8DF4,
      HIGH_INT                       = 0x8DF5,
      FRAMEBUFFER                    = 0x8D40,
      RENDERBUFFER                   = 0x8D41,
      RGBA4                          = 0x8056,
      RGB5_A1                        = 0x8057,
      RGB565                         = 0x8D62,
      DEPTH_COMPONENT16              = 0x81A5,
      STENCIL_INDEX8                 = 0x8D48,
      RENDERBUFFER_WIDTH             = 0x8D42,
      RENDERBUFFER_HEIGHT            = 0x8D43,
      RENDERBUFFER_INTERNAL_FORMAT   = 0x8D44,
      RENDERBUFFER_RED_SIZE          = 0x8D50,
      RENDERBUFFER_GREEN_SIZE        = 0x8D51,
      RENDERBUFFER_BLUE_SIZE         = 0x8D52,
      RENDERBUFFER_ALPHA_SIZE        = 0x8D53,
      RENDERBUFFER_DEPTH_SIZE        = 0x8D54,
      RENDERBUFFER_STENCIL_SIZE      = 0x8D55,
      FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE = 0x8CD0,
      FRAMEBUFFER_ATTACHMENT_OBJECT_NAME = 0x8CD1,
      FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL = 0x8CD2,
      FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE = 0x8CD3,
      COLOR_ATTACHMENT0              = 0x8CE0,
      DEPTH_ATTACHMENT               = 0x8D00,
      STENCIL_ATTACHMENT             = 0x8D20,
      NONE                           = 0,
      FRAMEBUFFER_COMPLETE           = 0x8CD5,
      FRAMEBUFFER_INCOMPLETE_ATTACHMENT = 0x8CD6,
      FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT = 0x8CD7,
      FRAMEBUFFER_INCOMPLETE_DIMENSIONS = 0x8CD9,
      FRAMEBUFFER_UNSUPPORTED        = 0x8CDD,
      FRAMEBUFFER_BINDING            = 0x8CA6,
      RENDERBUFFER_BINDING           = 0x8CA7,
      MAX_RENDERBUFFER_SIZE          = 0x84E8,
      INVALID_FRAMEBUFFER_OPERATION  = 0x0506,
    };

    enum Enum_3_0 {
      READ_BUFFER                    = 0x0C02,
      UNPACK_ROW_LENGTH              = 0x0CF2,
      UNPACK_SKIP_ROWS               = 0x0CF3,
      UNPACK_SKIP_PIXELS             = 0x0CF4,
      PACK_ROW_LENGTH                = 0x0D02,
      PACK_SKIP_ROWS                 = 0x0D03,
      PACK_SKIP_PIXELS               = 0x0D04,
      COLOR                          = 0x1800,
      DEPTH                          = 0x1801,
      STENCIL                        = 0x1802,
      RED                            = 0x1903,
      RGB8                           = 0x8051,
      RGBA8                          = 0x8058,
      RGB10_A2                       = 0x8059,
      TEXTURE_BINDING_3D             = 0x806A,
      UNPACK_SKIP_IMAGES             = 0x806D,
      UNPACK_IMAGE_HEIGHT            = 0x806E,
      TEXTURE_3D                     = 0x806F,
      TEXTURE_WRAP_R                 = 0x8072,
      MAX_3D_TEXTURE_SIZE            = 0x8073,
      UNSIGNED_INT_2_10_10_10_REV    = 0x8368,
      MAX_ELEMENTS_VERTICES          = 0x80E8,
      MAX_ELEMENTS_INDICES           = 0x80E9,
      TEXTURE_MIN_LOD                = 0x813A,
      TEXTURE_MAX_LOD                = 0x813B,
      TEXTURE_BASE_LEVEL             = 0x813C,
      TEXTURE_MAX_LEVEL              = 0x813D,
      MIN                            = 0x8007,
      MAX                            = 0x8008,
      DEPTH_COMPONENT24              = 0x81A6,
      MAX_TEXTURE_LOD_BIAS           = 0x84FD,
      TEXTURE_COMPARE_MODE           = 0x884C,
      TEXTURE_COMPARE_FUNC           = 0x884D,
      CURRENT_QUERY                  = 0x8865,
      QUERY_RESULT                   = 0x8866,
      QUERY_RESULT_AVAILABLE         = 0x8867,
      BUFFER_MAPPED                  = 0x88BC,
      BUFFER_MAP_POINTER             = 0x88BD,
      STREAM_READ                    = 0x88E1,
      STREAM_COPY                    = 0x88E2,
      STATIC_READ                    = 0x88E5,
      STATIC_COPY                    = 0x88E6,
      DYNAMIC_READ                   = 0x88E9,
      DYNAMIC_COPY                   = 0x88EA,
      MAX_DRAW_BUFFERS               = 0x8824,
      DRAW_BUFFER0                   = 0x8825,
      DRAW_BUFFER1                   = 0x8826,
      DRAW_BUFFER2                   = 0x8827,
      DRAW_BUFFER3                   = 0x8828,
      DRAW_BUFFER4                   = 0x8829,
      DRAW_BUFFER5                   = 0x882A,
      DRAW_BUFFER6                   = 0x882B,
      DRAW_BUFFER7                   = 0x882C,
      DRAW_BUFFER8                   = 0x882D,
      DRAW_BUFFER9                   = 0x882E,
      DRAW_BUFFER10                  = 0x882F,
      DRAW_BUFFER11                  = 0x8830,
      DRAW_BUFFER12                  = 0x8831,
      DRAW_BUFFER13                  = 0x8832,
      DRAW_BUFFER14                  = 0x8833,
      DRAW_BUFFER15                  = 0x8834,
      MAX_FRAGMENT_UNIFORM_COMPONENTS = 0x8B49,
      MAX_VERTEX_UNIFORM_COMPONENTS  = 0x8B4A,
      SAMPLER_3D                     = 0x8B5F,
      SAMPLER_2D_SHADOW              = 0x8B62,
      FRAGMENT_SHADER_DERIVATIVE_HINT = 0x8B8B,
      PIXEL_PACK_BUFFER              = 0x88EB,
      PIXEL_UNPACK_BUFFER            = 0x88EC,
      PIXEL_PACK_BUFFER_BINDING      = 0x88ED,
      PIXEL_UNPACK_BUFFER_BINDING    = 0x88EF,
      FLOAT_MAT2x3                   = 0x8B65,
      FLOAT_MAT2x4                   = 0x8B66,
      FLOAT_MAT3x2                   = 0x8B67,
      FLOAT_MAT3x4                   = 0x8B68,
      FLOAT_MAT4x2                   = 0x8B69,
      FLOAT_MAT4x3                   = 0x8B6A,
      SRGB                           = 0x8C40,
      SRGB8                          = 0x8C41,
      SRGB8_ALPHA8                   = 0x8C43,
      COMPARE_REF_TO_TEXTURE         = 0x884E,
      MAJOR_VERSION                  = 0x821B,
      MINOR_VERSION                  = 0x821C,
      NUM_EXTENSIONS                 = 0x821D,
      RGBA32F                        = 0x8814,
      RGB32F                         = 0x8815,
      RGBA16F                        = 0x881A,
      RGB16F                         = 0x881B,
      VERTEX_ATTRIB_ARRAY_INTEGER    = 0x88FD,
      MAX_ARRAY_TEXTURE_LAYERS       = 0x88FF,
      MIN_PROGRAM_TEXEL_OFFSET       = 0x8904,
      MAX_PROGRAM_TEXEL_OFFSET       = 0x8905,
      MAX_VARYING_COMPONENTS         = 0x8B4B,
      TEXTURE_2D_ARRAY               = 0x8C1A,
      TEXTURE_BINDING_2D_ARRAY       = 0x8C1D,
      R11F_G11F_B10F                 = 0x8C3A,
      UNSIGNED_INT_10F_11F_11F_REV   = 0x8C3B,
      RGB9_E5                        = 0x8C3D,
      UNSIGNED_INT_5_9_9_9_REV       = 0x8C3E,
      TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH = 0x8C76,
      TRANSFORM_FEEDBACK_BUFFER_MODE = 0x8C7F,
      MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS = 0x8C80,
      TRANSFORM_FEEDBACK_VARYINGS    = 0x8C83,
      TRANSFORM_FEEDBACK_BUFFER_START = 0x8C84,
      TRANSFORM_FEEDBACK_BUFFER_SIZE = 0x8C85,
      TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN = 0x8C88,
      RASTERIZER_DISCARD             = 0x8C89,
      MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS = 0x8C8A,
      MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS = 0x8C8B,
      INTERLEAVED_ATTRIBS            = 0x8C8C,
      SEPARATE_ATTRIBS               = 0x8C8D,
      TRANSFORM_FEEDBACK_BUFFER      = 0x8C8E,
      TRANSFORM_FEEDBACK_BUFFER_BINDING = 0x8C8F,
      RGBA32UI                       = 0x8D70,
      RGB32UI                        = 0x8D71,
      RGBA16UI                       = 0x8D76,
      RGB16UI                        = 0x8D77,
      RGBA8UI                        = 0x8D7C,
      RGB8UI                         = 0x8D7D,
      RGBA32I                        = 0x8D82,
      RGB32I                         = 0x8D83,
      RGBA16I                        = 0x8D88,
      RGB16I                         = 0x8D89,
      RGBA8I                         = 0x8D8E,
      RGB8I                          = 0x8D8F,
      RED_INTEGER                    = 0x8D94,
      RGB_INTEGER                    = 0x8D98,
      RGBA_INTEGER                   = 0x8D99,
      SAMPLER_2D_ARRAY               = 0x8DC1,
      SAMPLER_2D_ARRAY_SHADOW        = 0x8DC4,
      SAMPLER_CUBE_SHADOW            = 0x8DC5,
      UNSIGNED_INT_VEC2              = 0x8DC6,
      UNSIGNED_INT_VEC3              = 0x8DC7,
      UNSIGNED_INT_VEC4              = 0x8DC8,
      INT_SAMPLER_2D                 = 0x8DCA,
      INT_SAMPLER_3D                 = 0x8DCB,
      INT_SAMPLER_CUBE               = 0x8DCC,
      INT_SAMPLER_2D_ARRAY           = 0x8DCF,
      UNSIGNED_INT_SAMPLER_2D        = 0x8DD2,
      UNSIGNED_INT_SAMPLER_3D        = 0x8DD3,
      UNSIGNED_INT_SAMPLER_CUBE      = 0x8DD4,
      UNSIGNED_INT_SAMPLER_2D_ARRAY  = 0x8DD7,
      BUFFER_ACCESS_FLAGS            = 0x911F,
      BUFFER_MAP_LENGTH              = 0x9120,
      BUFFER_MAP_OFFSET              = 0x9121,
      DEPTH_COMPONENT32F             = 0x8CAC,
      DEPTH32F_STENCIL8              = 0x8CAD,
      FLOAT_32_UNSIGNED_INT_24_8_REV = 0x8DAD,
      FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING = 0x8210,
      FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE = 0x8211,
      FRAMEBUFFER_ATTACHMENT_RED_SIZE = 0x8212,
      FRAMEBUFFER_ATTACHMENT_GREEN_SIZE = 0x8213,
      FRAMEBUFFER_ATTACHMENT_BLUE_SIZE = 0x8214,
      FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE = 0x8215,
      FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE = 0x8216,
      FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE = 0x8217,
      FRAMEBUFFER_DEFAULT            = 0x8218,
      FRAMEBUFFER_UNDEFINED          = 0x8219,
      DEPTH_STENCIL_ATTACHMENT       = 0x821A,
      DEPTH_STENCIL                  = 0x84F9,
      UNSIGNED_INT_24_8              = 0x84FA,
      DEPTH24_STENCIL8               = 0x88F0,
      UNSIGNED_NORMALIZED            = 0x8C17,
      DRAW_FRAMEBUFFER_BINDING       = 0x8CA6,
      READ_FRAMEBUFFER               = 0x8CA8,
      DRAW_FRAMEBUFFER               = 0x8CA9,
      READ_FRAMEBUFFER_BINDING       = 0x8CAA,
      RENDERBUFFER_SAMPLES           = 0x8CAB,
      FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER = 0x8CD4,
      MAX_COLOR_ATTACHMENTS          = 0x8CDF,
      COLOR_ATTACHMENT1              = 0x8CE1,
      COLOR_ATTACHMENT2              = 0x8CE2,
      COLOR_ATTACHMENT3              = 0x8CE3,
      COLOR_ATTACHMENT4              = 0x8CE4,
      COLOR_ATTACHMENT5              = 0x8CE5,
      COLOR_ATTACHMENT6              = 0x8CE6,
      COLOR_ATTACHMENT7              = 0x8CE7,
      COLOR_ATTACHMENT8              = 0x8CE8,
      COLOR_ATTACHMENT9              = 0x8CE9,
      COLOR_ATTACHMENT10             = 0x8CEA,
      COLOR_ATTACHMENT11             = 0x8CEB,
      COLOR_ATTACHMENT12             = 0x8CEC,
      COLOR_ATTACHMENT13             = 0x8CED,
      COLOR_ATTACHMENT14             = 0x8CEE,
      COLOR_ATTACHMENT15             = 0x8CEF,
      FRAMEBUFFER_INCOMPLETE_MULTISAMPLE = 0x8D56,
      MAX_SAMPLES                    = 0x8D57,
      HALF_FLOAT                     = 0x140B,
      MAP_READ_BIT                   = 0x0001,
      MAP_WRITE_BIT                  = 0x0002,
      MAP_INVALIDATE_RANGE_BIT       = 0x0004,
      MAP_INVALIDATE_BUFFER_BIT      = 0x0008,
      MAP_FLUSH_EXPLICIT_BIT         = 0x0010,
      MAP_UNSYNCHRONIZED_BIT         = 0x0020,
      RG                             = 0x8227,
      RG_INTEGER                     = 0x8228,
      R8                             = 0x8229,
      RG8                            = 0x822B,
      R16F                           = 0x822D,
      R32F                           = 0x822E,
      RG16F                          = 0x822F,
      RG32F                          = 0x8230,
      R8I                            = 0x8231,
      R8UI                           = 0x8232,
      R16I                           = 0x8233,
      R16UI                          = 0x8234,
      R32I                           = 0x8235,
      R32UI                          = 0x8236,
      RG8I                           = 0x8237,
      RG8UI                          = 0x8238,
      RG16I                          = 0x8239,
      RG16UI                         = 0x823A,
      RG32I                          = 0x823B,
      RG32UI                         = 0x823C,
      VERTEX_ARRAY_BINDING           = 0x85B5,
      R8_SNORM                       = 0x8F94,
      RG8_SNORM                      = 0x8F95,
      RGB8_SNORM                     = 0x8F96,
      RGBA8_SNORM                    = 0x8F97,
      SIGNED_NORMALIZED              = 0x8F9C,
      PRIMITIVE_RESTART_FIXED_INDEX  = 0x8D69,
      COPY_READ_BUFFER               = 0x8F36,
      COPY_WRITE_BUFFER              = 0x8F37,
      COPY_READ_BUFFER_BINDING       = 0x8F36,
      COPY_WRITE_BUFFER_BINDING      = 0x8F37,
      UNIFORM_BUFFER                 = 0x8A11,
      UNIFORM_BUFFER_BINDING         = 0x8A28,
      UNIFORM_BUFFER_START           = 0x8A29,
      UNIFORM_BUFFER_SIZE            = 0x8A2A,
      MAX_VERTEX_UNIFORM_BLOCKS      = 0x8A2B,
      MAX_FRAGMENT_UNIFORM_BLOCKS    = 0x8A2D,
      MAX_COMBINED_UNIFORM_BLOCKS    = 0x8A2E,
      MAX_UNIFORM_BUFFER_BINDINGS    = 0x8A2F,
      MAX_UNIFORM_BLOCK_SIZE         = 0x8A30,
      MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS = 0x8A31,
      MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS = 0x8A33,
      UNIFORM_BUFFER_OFFSET_ALIGNMENT = 0x8A34,
      ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH = 0x8A35,
      ACTIVE_UNIFORM_BLOCKS          = 0x8A36,
      UNIFORM_TYPE                   = 0x8A37,
      UNIFORM_SIZE                   = 0x8A38,
      UNIFORM_NAME_LENGTH            = 0x8A39,
      UNIFORM_BLOCK_INDEX            = 0x8A3A,
      UNIFORM_OFFSET                 = 0x8A3B,
      UNIFORM_ARRAY_STRIDE           = 0x8A3C,
      UNIFORM_MATRIX_STRIDE          = 0x8A3D,
      UNIFORM_IS_ROW_MAJOR           = 0x8A3E,
      UNIFORM_BLOCK_BINDING          = 0x8A3F,
      UNIFORM_BLOCK_DATA_SIZE        = 0x8A40,
      UNIFORM_BLOCK_NAME_LENGTH      = 0x8A41,
      UNIFORM_BLOCK_ACTIVE_UNIFORMS  = 0x8A42,
      UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES = 0x8A43,
      UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER = 0x8A44,
      UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER = 0x8A46,
      INVALID_INDEX                  = 0xFFFFFFFFu,
      MAX_VERTEX_OUTPUT_COMPONENTS   = 0x9122,
      MAX_FRAGMENT_INPUT_COMPONENTS  = 0x9125,
      MAX_SERVER_WAIT_TIMEOUT        = 0x9111,
      OBJECT_TYPE                    = 0x9112,
      SYNC_CONDITION                 = 0x9113,
      SYNC_STATUS                    = 0x9114,
      SYNC_FLAGS                     = 0x9115,
      SYNC_FENCE                     = 0x9116,
      SYNC_GPU_COMMANDS_COMPLETE     = 0x9117,
      UNSIGNALED                     = 0x9118,
      SIGNALED                       = 0x9119,
      ALREADY_SIGNALED               = 0x911A,
      TIMEOUT_EXPIRED                = 0x911B,
      CONDITION_SATISFIED            = 0x911C,
      WAIT_FAILED                    = 0x911D,
      SYNC_FLUSH_COMMANDS_BIT        = 0x00000001,
      TIMEOUT_IGNORED                = 0xFFFFFFFFFFFFFFFFull,
      VERTEX_ATTRIB_ARRAY_DIVISOR    = 0x88FE,
      ANY_SAMPLES_PASSED             = 0x8C2F,
      ANY_SAMPLES_PASSED_CONSERVATIVE = 0x8D6A,
      SAMPLER_BINDING                = 0x8919,
      RGB10_A2UI                     = 0x906F,
      TEXTURE_SWIZZLE_R              = 0x8E42,
      TEXTURE_SWIZZLE_G              = 0x8E43,
      TEXTURE_SWIZZLE_B              = 0x8E44,
      TEXTURE_SWIZZLE_A              = 0x8E45,
      GREEN                          = 0x1904,
      BLUE                           = 0x1905,
      INT_2_10_10_10_REV             = 0x8D9F,
      TRANSFORM_FEEDBACK             = 0x8E22,
      TRANSFORM_FEEDBACK_PAUSED      = 0x8E23,
      TRANSFORM_FEEDBACK_ACTIVE      = 0x8E24,
      TRANSFORM_FEEDBACK_BINDING     = 0x8E25,
      PROGRAM_BINARY_RETRIEVABLE_HINT = 0x8257,
      PROGRAM_BINARY_LENGTH          = 0x8741,
      NUM_PROGRAM_BINARY_FORMATS     = 0x87FE,
      PROGRAM_BINARY_FORMATS         = 0x87FF,
      COMPRESSED_R11_EAC             = 0x9270,
      COMPRESSED_SIGNED_R11_EAC      = 0x9271,
      COMPRESSED_RG11_EAC            = 0x9272,
      COMPRESSED_SIGNED_RG11_EAC     = 0x9273,
      COMPRESSED_RGB8_ETC2           = 0x9274,
      COMPRESSED_SRGB8_ETC2          = 0x9275,
      COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9276,
      COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = 0x9277,
      COMPRESSED_RGBA8_ETC2_EAC      = 0x9278,
      COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = 0x9279,
      TEXTURE_IMMUTABLE_FORMAT       = 0x912F,
      MAX_ELEMENT_INDEX              = 0x8D6B,
      NUM_SAMPLE_COUNTS              = 0x9380,
      TEXTURE_IMMUTABLE_LEVELS       = 0x82DF,
    };

    enum {
      TEXTURE0,  TEXTURE1,  TEXTURE2,  TEXTURE3,  TEXTURE4,  TEXTURE5,  TEXTURE6,  TEXTURE7,
      TEXTURE8,  TEXTURE9,  TEXTURE10, TEXTURE11, TEXTURE12, TEXTURE13, TEXTURE14, TEXTURE15,
      TEXTURE16, TEXTURE17, TEXTURE18, TEXTURE19, TEXTURE20, TEXTURE21, TEXTURE22, TEXTURE23,
      TEXTURE24, TEXTURE25, TEXTURE26, TEXTURE27, TEXTURE28, TEXTURE29, TEXTURE30, TEXTURE31,

#if 0
      TEXTURE32, TEXTURE33, TEXTURE34, TEXTURE35, TEXTURE36, TEXTURE37, TEXTURE38, TEXTURE39,
      TEXTURE40, TEXTURE41, TEXTURE42, TEXTURE43, TEXTURE44, TEXTURE45, TEXTURE46, TEXTURE47,
      TEXTURE48, TEXTURE49, TEXTURE50, TEXTURE51, TEXTURE52, TEXTURE53, TEXTURE54, TEXTURE55,
      TEXTURE56, TEXTURE57, TEXTURE58, TEXTURE59, TEXTURE60, TEXTURE61, TEXTURE62, TEXTURE63,

      TEXTURE64, TEXTURE65, TEXTURE66, TEXTURE67, TEXTURE68, TEXTURE69, TEXTURE70, TEXTURE71,
      TEXTURE72, TEXTURE73, TEXTURE74, TEXTURE75, TEXTURE76, TEXTURE77, TEXTURE78, TEXTURE79,
      TEXTURE80, TEXTURE81, TEXTURE82, TEXTURE83, TEXTURE84, TEXTURE85, TEXTURE86, TEXTURE87,
      TEXTURE88, TEXTURE89, TEXTURE90, TEXTURE91, TEXTURE92, TEXTURE93, TEXTURE94, TEXTURE95,

      TEXTURE96,  TEXTURE97,  TEXTURE98, TEXTURE99, TEXTURE100, TEXTURE101, TEXTURE102, TEXTURE103,
      TEXTURE104, TEXTURE105, TEXTURE106, TEXTURE107, TEXTURE108, TEXTURE109, TEXTURE110, TEXTURE111,
      TEXTURE112, TEXTURE113, TEXTURE114, TEXTURE115, TEXTURE116, TEXTURE117, TEXTURE118, TEXTURE119,
      TEXTURE120, TEXTURE121, TEXTURE122, TEXTURE123, TEXTURE124, TEXTURE125, TEXTURE126, TEXTURE127,
#endif
    };

    std::int32_t GetError(void) const;

    void Viewport(std::int32_t x, std::int32_t y, std::int32_t width, std::int32_t height) const;

    void Clear(unsigned mask) const;
    void ClearColor(float red, float green, float blue, float alpha) const;
    void ClearDepthf(float d) const;
    void ClearStencil(std::int32_t s) const;

    std::uint32_t CreateShader(std::uint32_t type) const;
    void DeleteShader(std::uint32_t shader) const;
    void ShaderSource(std::uint32_t shader, std::int32_t count, const char * const * string, const std::int32_t *length) const;
    void CompileShader(std::uint32_t shader) const;
    void GetShaderiv(std::uint32_t shader, std::int32_t pname, std::int32_t *params) const;
    void GetShaderInfoLog(std::uint32_t shader, std::int32_t bufSize, std::int32_t *length, char *infoLog) const;

    std::uint32_t CreateProgram(void) const;
    void DeleteProgram(std::uint32_t program) const;
    void UseProgram(std::uint32_t program) const;
    void ValidateProgram(std::uint32_t program) const;
    void AttachShader(std::uint32_t program, std::uint32_t shader) const;
    void LinkProgram(std::uint32_t program) const;
    void GetProgramiv(std::uint32_t program, std::int32_t pname, std::int32_t *params) const;
    void GetProgramInfoLog(std::uint32_t program, std::int32_t bufSize, std::int32_t *length, char *infoLog) const;

    void GenVertexArrays(std::int32_t n, std::uint32_t *arrays) const;
    void DeleteVertexArrays(std::int32_t n, const std::uint32_t *arrays) const;
    void BindVertexArray(std::uint32_t array) const;
    void EnableVertexAttribArray(std::uint32_t index) const;
    void VertexAttribPointer(std::uint32_t index, std::int32_t size, std::uint32_t type, bool normalized, std::int32_t stride, const void *pointer) const;

    void GenBuffers(std::int32_t n, std::uint32_t *buffers) const;
    void DeleteBuffers(std::int32_t n, const std::uint32_t *buffers) const;
    void BindBuffer(std::uint32_t target, std::uint32_t buffer) const;
    void BindBufferRange(std::uint32_t target, std::uint32_t index, std::uint32_t buffer, std::uint32_t offset, std::uint32_t size) const;
    void BindBufferBase(std::uint32_t target, std::uint32_t index, std::uint32_t buffer) const;
    void BufferData(std::uint32_t target, std::uint32_t size, const void *data, std::uint32_t usage) const;

    void GenerateMipmap(std::uint32_t target) const;
    void GenFramebuffers(std::int32_t n, std::uint32_t *framebuffers) const;
    void GenRenderbuffers(std::int32_t n, std::uint32_t *renderbuffers) const;

    void GenTextures(std::int32_t n, std::uint32_t *textures) const;
    void ActiveTexture(unsigned texture) const;
    std::int32_t GetUniformLocation(std::uint32_t program, const char *name) const;
    void BindTexture(std::uint32_t target, std::uint32_t texture) const;
    
    void TexImage2D(std::uint32_t target, std::int32_t level, std::int32_t internalformat, std::int32_t width, std::int32_t height, std::int32_t border, std::uint32_t format, std::uint32_t type, const void *pixels) const;
    void TexParameterf(std::uint32_t target, std::uint32_t pname, float param) const;
    void TexParameterfv(std::uint32_t target, std::uint32_t pname, const float *params) const;
    void TexParameteri(std::uint32_t target, std::uint32_t pname, std::int32_t param) const;
    void TexParameteriv(std::uint32_t target, std::uint32_t pname, const std::int32_t *params) const;
    void TexSubImage2D(std::uint32_t target, std::int32_t level, std::int32_t xoffset, std::int32_t yoffset, std::int32_t width, std::int32_t height, std::uint32_t format, std::uint32_t type, const void *pixels) const;

    void Uniform1f(std::int32_t location, float v0) const;
    void Uniform1fv(std::int32_t location, std::int32_t count, const float *value) const;
    void Uniform1i(std::int32_t location, std::int32_t v0) const;
    void Uniform1iv(std::int32_t location, std::int32_t count, const std::int32_t *value) const;
    void Uniform2f(std::int32_t location, float v0, float v1) const;
    void Uniform2fv(std::int32_t location, std::int32_t count, const float *value) const;
    void Uniform2i(std::int32_t location, std::int32_t v0, std::int32_t v1) const;
    void Uniform2iv(std::int32_t location, std::int32_t count, const std::int32_t *value) const;
    void Uniform3f(std::int32_t location, float v0, float v1, float v2) const;
    void Uniform3fv(std::int32_t location, std::int32_t count, const float *value) const;
    void Uniform3i(std::int32_t location, std::int32_t v0, std::int32_t v1, std::int32_t v2) const;
    void Uniform3iv(std::int32_t location, std::int32_t count, const std::int32_t *value) const;
    void Uniform4f(std::int32_t location, float v0, float v1, float v2, float v3) const;
    void Uniform4fv(std::int32_t location, std::int32_t count, const float *value) const;
    void Uniform4i(std::int32_t location, std::int32_t v0, std::int32_t v1, std::int32_t v2, std::int32_t v3) const;
    void Uniform4iv(std::int32_t location, std::int32_t count, const std::int32_t *value) const;
    void UniformMatrix2fv(std::int32_t location, std::int32_t count, bool transpose, const float *value) const;
    void UniformMatrix3fv(std::int32_t location, std::int32_t count, bool transpose, const float *value) const;
    void UniformMatrix4fv(std::int32_t location, std::int32_t count, bool transpose, const float *value) const;

    void DrawArrays(std::uint32_t mode, std::int32_t first, std::int32_t count) const;
    void DrawArraysInstanced(std::uint32_t mode, std::int32_t first, std::int32_t count, std::int32_t instancecount) const;
    void DrawBuffers(std::int32_t n, const std::uint32_t *bufs) const;
    void DrawElements(std::uint32_t mode, std::int32_t count, std::uint32_t type, const void *indices) const;
    void DrawElementsInstanced(std::uint32_t mode, std::int32_t count, std::uint32_t type, const void *indices, std::int32_t instancecount) const;
    void DrawRangeElements(std::uint32_t mode, std::uint32_t start, std::uint32_t end, std::int32_t count, std::uint32_t type, const void *indices) const;
  };
}

#endif//__ORL_INTERNAL_DRIVER_HPP__
