#pragma once


typedef struct {
    uint8_t data[4][4];
} Matrix4x4;

// Core AES operations
Matrix4x4 AddRoundKey(Matrix4x4 state, Matrix4x4 roundKey);
Matrix4x4 SubBytes(Matrix4x4 state);
Matrix4x4 ShiftRows(Matrix4x4 state);
Matrix4x4 MixColumns(Matrix4x4 state);
Matrix4x4 init_Matrix(uint8_t *input);

// Key padding
void padPassword(const char* passwordStr, uint8_t key[32]);

// AES-256 encryption
void AES256_encrypt(uint8_t *input, uint8_t *key, uint8_t *output);