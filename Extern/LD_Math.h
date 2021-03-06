/*
    This header declares functions and values that can be platform dependant.
    In the definitions goes part of the non-portable code.
    By default it depends on NasmMath so it must be linked.
*/

#ifndef _LD_MATH_H
#define _LD_MATH_H

   /*  The same identity matrix can be defined in many othar places
        if it's not defined, define it here */
    #ifndef __IDENTITY_MATRIX_4X4_FLOAT_
    #define __IDENTITY_MATRIX_4X4_FLOAT_
    
    extern float Identity_Matrix_4x4[16];  
/*    
    float Identity_Matrix_4x4[16]=
        {
            1.f,0.f,0.f,0.f,
            0.f,1.f,0.f,0.f,
            0.f,0.f,1.f,0.f,
            0.f,0.f,0.f,1.f
        };
*/
    #endif  

#ifdef __cplusplus
extern "C" 
{
#endif

    float V2Distance(float * Point_A, float * Point_B);
    void V2Degrees_FPU(float * Vec2D, float * Scalar_Result);
    void V2DegreesV2_FPU(float * Point_A, float * Point_B, float * Scalar_Result);

    void M4x4ScalarMUL(void * Matrix, float Scalar, void * Result_Matrix);
    void M4x4MUL(float * A, float *B, float * Result);
    void M4x4V4MUL(float * Matrix, float *Vector, float * Result);
    void M4x4V4_PseudoV3_W1_MUL (float * Matrix, float * Vector, float * VectorResultado);
    void M4x4_PseudoM3x3_V4_PseudoV3_W1_MUL 
    (float * Matrix, float * Vector, float * VectorResultado);
    void M4INVERSE(void * Result, void * Matrix);
#define M4x4_Inverse(Matrix,Return) M4INVERSE(Return,Matrix)
	
    void M2MUL(void * Result, void * A, void * B);
   #define M2x2MUL(A,B,R) M2MUL(R,A,B);
	float M2DET(void * Matrix);

    void NormalizeVec2 (float * Vec2, float * Result);
    void NormalizeDoubleVec2 (double * Vec2, double * Result);
    void NormalizeVec3(float *A, float *R);
    void NormalizeVec4(float * Vec4, float * Result);

    void QuaternionMUL (float * A, float *B, float * Result);
    void QuaternionToMatrix4x4(float * Quaternion, float * Matrix);
    void AxisAngleToQuaternion(float * Axis, float Angle, float * NewQuartenion);  

    float V2V2Dot (float * Vec2_A, float * Vec2_B);
    float V3V3Dot (float * Vec3_A, float * Vec3_B);
    float V4V4Dot (float * Vec4_A, float * Vec4_B);
    void CrossProductVec3(float *A, float *B, float *C);

    void V2ScalarMUL(float * Vec2_A, float Scalar_B, float * Vec2_Result);
    void V3ScalarMUL(void * Vec3_A, float Scalar_B, void * Vec3_Result);
    void V4ScalarMUL(void * Vec4_A, float Scalar_B, void * Vec4_Result);
    void V4ScalarDIV(void * Vec4_A, float Scalar_B, void * Vec4_Result);

    void V2V2ADD(float * Vec2_A, float * Vec2_B, float * Vec2_Result);
    void V2V2SUB(float * Vec2_A, float * Vec2_B, float * Vec2_Result);
    void V3V3ADD(float * Vec3_A, float * Vec3_B,float * Vec3_Result);
    void V3V3SUB(float * Vec3_A, float * Vec3_B,float * Vec3_Result);
    void V3V3MUL(void * Vec3_A, void * Vec3_B, void * Result);
    void V4V4ADD (float * A, float *B, float * Result);
    void V4V4SUB (float * A, float *B, float * Result);

    void V4Lerp(void * vec4_A, void * vec4_B, float factor, void * Result);
    void V3Lerp(void * vec3_A, void * vec3_B, float factor, void * Result);
    void V2Lerp(void * vec2_A, void * vec2_B, float factor, void * Result);
    float ScalarLerp(float A, float B, float factor);
    double DoubleScalarLerp(double A, double B, double factor);

    void V2CalculatePerpendicular
    (float * Vec2_A,float * Vec2_Result,float ClockWise_Multiplier);

    void V2Rotate_FPU(float * Vec2_A, float * Angle_Degrees, float * Vec2_Result);
    void QuaternionRotateV3(void * Quaternion, void * Vec3, void * Result);
    
    void PerspectiveProjectionMatrix4x4
    (float *matrix, float fovyInDegrees, float aspectRatio,float znear, float zfar);
    void OrthogonalProjectionMatrix4x4
    (float *matrix, float Width, float Height, float znear, float zfar);
    void ViewLookAt(float * matrix, float * Vec3From,float * Vec3to, float * Vec3Up);

#ifdef __cplusplus
}
#endif

#endif
