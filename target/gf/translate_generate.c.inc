/*
* QEMU GF CPU
*/
//#include <stdbool.h>
//#include "tcg/tcg-op.h"
//#include "tcg/tcg.h"
//#include "cpu.h"
//#include "translate.c"
//#include <tcg-op.h>

// static char *reg_names[NUMBER_OF_CPU_REGISTERS] = {"x0", "x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8", "x9", "x10", "x11", "x12", "x13", "x14", "x15", "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31", "pc", "ia"};
// static TCGv cpu_gpr[NUMBER_OF_CPU_REGISTERS];


// void gf_cpu_tcg_init(void)
// {
// 	for (i = 0; i < NUMBER_OF_CPU_REGISTERS; i++) {
// 		cpu_gpr[i] = tcg_global_mem_new_tl(tcg_env, offsetof(CPUGfState, cpu_gpr[i]), reg_names[i]);
// 	}
// 	cpu_x31 = tcg_global_mem_new_tl(tcg_env, offsetof(CPUGfState, cpu_x31), reg_names[i]);
// 	cpu_pc = tcg_global_mem_new_tl(tcg_env, offsetof(CPUGfState, cpu_pc), reg_names[i]);
// 	cpu_ia = tcg_global_mem_new_tl(tcg_env, offsetof(CPUGfState, cpu_ia), reg_names[i]);
// }

// typedef struct DisasContext DisasContext;

// /* This is the state at translation time. */
// struct DisasContext {
// 	DisasContextBase base;

// 	CPUGfState *env;
// };

#if 0
static bool tcg_trans_Lui(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_movi_tl(cpu_pc, arg_1);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Lui(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	uint64_t tmp_2 = arg_1 * 0x0004;
	uint64_t tmp_3 = 0x0000 + tmp_2;
	uint64_t tmp_4 = (0x000 << 20) | arg_0;
	tcg_trans_Lui(ctx, tmp_3, tmp_4);
	return true;
}

static bool tcg_trans_Auipc(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_2, cpu_ia);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_3, tmp_2, arg_1);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_3);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Auipc(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	uint64_t tmp_2 = arg_1 * 0x0004;
	uint64_t tmp_3 = 0x0000 + tmp_2;
	uint64_t tmp_4 = (0x000 << 20) | arg_0;
	tcg_trans_Auipc(ctx, tmp_3, tmp_4);
	return true;
}

static bool tcg_trans_Jal(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_2, cpu_pc);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_2);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_ia);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_4, tmp_3, arg_1);
	tcg_gen_mov_tl(cpu_pc, tmp_4);
	ctx->base.is_jmp = DISAS_NORETURN;
	return true;
}

static bool trans_Jal(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	uint64_t tmp_2 = arg_1 * 0x0004;
	uint64_t tmp_3 = 0x0000 + tmp_2;
	uint64_t tmp_4 = (arg_0 & 0x80000) >> 19;
	uint64_t tmp_5 = arg_0 & 0x000FF;
	uint64_t tmp_6 = (tmp_5 << 1) | tmp_4;
	uint64_t tmp_7 = (arg_0 & 0x00100) >> 8;
	uint64_t tmp_8 = (tmp_7 << 9) | tmp_6;
	uint64_t tmp_9 = (arg_0 & 0x7FE00) >> 9;
	uint64_t tmp_10 = (tmp_9 << 10) | tmp_8;
	uint64_t tmp_11 = (0b0 << 20) | tmp_10;
	uint64_t tmp_12 = (0b11111111111 << 21) * (tmp_11 & (1 << 21) >> 21);
	uint64_t tmp_13 = tmp_12 | tmp_11;
	tcg_trans_Jal(ctx, tmp_3, tmp_13);
	return true;
}

static bool tcg_trans_Jalr(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_pc);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_3);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_4, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_5, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_4, tmp_5);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_6, tmp_4, arg_2);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_andi_tl(tmp_7, tmp_6, 0xFFFFFFFE);
	tcg_gen_mov_tl(cpu_pc, tmp_7);
	ctx->base.is_jmp = DISAS_NORETURN;
	return true;
}

static bool trans_Jalr(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0xFFFFF << 12) * (arg_0 & (1 << 12) >> 12);
	uint64_t tmp_8 = tmp_7 | arg_0;
	tcg_trans_Jalr(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Beq(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_510 = gen_new_label();
	TCGLabel *l_407 = gen_new_label();
	TCGLabel *exit_190 = gen_new_label();
	TCGLabel *l_190 = gen_new_label();
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_0 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_setcond_tl(TCG_COND_EQ, tmp_7, tmp_3, tmp_5);
	TCGLabel *branch_l_453 = gen_new_label();
	tcg_gen_brcondi_tl(TCG_COND_EQ, tmp_7, 0, branch_l_453);
	tcg_gen_br(l_407);
	gen_set_label(branch_l_453);
	tcg_gen_br(l_510);
	gen_set_label(l_510);
	tcg_gen_br(l_190);
	gen_set_label(l_190);
	tcg_gen_br(exit_190);
	gen_set_label(l_407);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_8, cpu_ia);
	TCGv tmp_9 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_9, tmp_8, arg_2);
	tcg_gen_mov_tl(cpu_pc, tmp_9);
	tcg_gen_br(l_190);
	gen_set_label(exit_190);
	ctx->base.is_jmp = DISAS_NORETURN;
	return true;
}

static bool trans_Beq(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (arg_2 & 0x800) >> 11;
	uint64_t tmp_8 = arg_2 & 0x001;
	uint64_t tmp_9 = (tmp_8 << 1) | tmp_7;
	uint64_t tmp_10 = (arg_2 & 0x7FE) >> 1;
	uint64_t tmp_11 = (tmp_10 << 2) | tmp_9;
	uint64_t tmp_12 = (0b0 << 12) | tmp_11;
	uint64_t tmp_13 = (0b1111111111111111111 << 13) * (tmp_12 & (1 << 13) >> 13);
	uint64_t tmp_14 = tmp_13 | tmp_12;
	tcg_trans_Beq(ctx, tmp_4, tmp_6, tmp_14);
	return true;
}

static bool tcg_trans_Bne(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_29 = gen_new_label();
	TCGLabel *l_210 = gen_new_label();
	TCGLabel *exit_32 = gen_new_label();
	TCGLabel *l_32 = gen_new_label();
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_0 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_setcond_tl(TCG_COND_NE, tmp_7, tmp_3, tmp_5);
	TCGLabel *branch_l_2 = gen_new_label();
	tcg_gen_brcondi_tl(TCG_COND_EQ, tmp_7, 0, branch_l_2);
	tcg_gen_br(l_210);
	gen_set_label(branch_l_2);
	tcg_gen_br(l_29);
	gen_set_label(l_29);
	tcg_gen_br(l_32);
	gen_set_label(l_32);
	tcg_gen_br(exit_32);
	gen_set_label(l_210);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_8, cpu_ia);
	TCGv tmp_9 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_9, tmp_8, arg_2);
	tcg_gen_mov_tl(cpu_pc, tmp_9);
	tcg_gen_br(l_32);
	gen_set_label(exit_32);
	ctx->base.is_jmp = DISAS_NORETURN;
	return true;
}

static bool trans_Bne(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (arg_1 & 0x800) >> 11;
	uint64_t tmp_8 = arg_1 & 0x001;
	uint64_t tmp_9 = (tmp_8 << 1) | tmp_7;
	uint64_t tmp_10 = (arg_1 & 0x7FE) >> 1;
	uint64_t tmp_11 = (tmp_10 << 2) | tmp_9;
	uint64_t tmp_12 = (0b0 << 12) | tmp_11;
	uint64_t tmp_13 = (0b1111111111111111111 << 13) * (tmp_12 & (1 << 13) >> 13);
	uint64_t tmp_14 = tmp_13 | tmp_12;
	tcg_trans_Bne(ctx, tmp_4, tmp_6, tmp_14);
	return true;
}

static bool tcg_trans_Blt(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_318 = gen_new_label();
	TCGLabel *l_62 = gen_new_label();
	TCGLabel *exit_296 = gen_new_label();
	TCGLabel *l_296 = gen_new_label();
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_0 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_setcond_tl(TCG_LT_NE, tmp_7, tmp_3, tmp_5);
	TCGLabel *branch_l_280 = gen_new_label();
	tcg_gen_brcondi_tl(TCG_COND_EQ, tmp_7, 0, branch_l_280);
	tcg_gen_br(l_62);
	gen_set_label(branch_l_280);
	tcg_gen_br(l_318);
	gen_set_label(l_318);
	tcg_gen_br(l_296);
	gen_set_label(l_296);
	tcg_gen_br(exit_296);
	gen_set_label(l_62);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_8, cpu_ia);
	TCGv tmp_9 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_9, tmp_8, arg_2);
	tcg_gen_mov_tl(cpu_pc, tmp_9);
	tcg_gen_br(l_296);
	gen_set_label(exit_296);
	ctx->base.is_jmp = DISAS_NORETURN;
	return true;
}

static bool trans_Blt(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (arg_2 & 0x800) >> 11;
	uint64_t tmp_8 = arg_2 & 0x001;
	uint64_t tmp_9 = (tmp_8 << 1) | tmp_7;
	uint64_t tmp_10 = (arg_2 & 0x7FE) >> 1;
	uint64_t tmp_11 = (tmp_10 << 2) | tmp_9;
	uint64_t tmp_12 = (0b0 << 12) | tmp_11;
	uint64_t tmp_13 = (0b1111111111111111111 << 13) * (tmp_12 & (1 << 13) >> 13);
	uint64_t tmp_14 = tmp_13 | tmp_12;
	tcg_trans_Blt(ctx, tmp_4, tmp_6, tmp_14);
	return true;
}

static bool tcg_trans_Bge(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_413 = gen_new_label();
	TCGLabel *l_42 = gen_new_label();
	TCGLabel *exit_417 = gen_new_label();
	TCGLabel *l_417 = gen_new_label();
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_0 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_setcond_tl(TCG_GE_NE, tmp_7, tmp_3, tmp_5);
	TCGLabel *branch_l_94 = gen_new_label();
	tcg_gen_brcondi_tl(TCG_COND_EQ, tmp_7, 0, branch_l_94);
	tcg_gen_br(l_42);
	gen_set_label(branch_l_94);
	tcg_gen_br(l_413);
	gen_set_label(l_413);
	tcg_gen_br(l_417);
	gen_set_label(l_417);
	tcg_gen_br(exit_417);
	gen_set_label(l_42);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_8, cpu_ia);
	TCGv tmp_9 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_9, tmp_8, arg_2);
	tcg_gen_mov_tl(cpu_pc, tmp_9);
	tcg_gen_br(l_417);
	gen_set_label(exit_417);
	ctx->base.is_jmp = DISAS_NORETURN;
	return true;
}

static bool trans_Bge(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_0 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (arg_2 & 0x800) >> 11;
	uint64_t tmp_8 = arg_2 & 0x001;
	uint64_t tmp_9 = (tmp_8 << 1) | tmp_7;
	uint64_t tmp_10 = (arg_2 & 0x7FE) >> 1;
	uint64_t tmp_11 = (tmp_10 << 2) | tmp_9;
	uint64_t tmp_12 = (0b0 << 12) | tmp_11;
	uint64_t tmp_13 = (0b1111111111111111111 << 13) * (tmp_12 & (1 << 13) >> 13);
	uint64_t tmp_14 = tmp_13 | tmp_12;
	tcg_trans_Bge(ctx, tmp_4, tmp_6, tmp_14);
	return true;
}

static bool tcg_trans_Bltu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_258 = gen_new_label();
	TCGLabel *l_401 = gen_new_label();
	TCGLabel *exit_458 = gen_new_label();
	TCGLabel *l_458 = gen_new_label();
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_0 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_setcond_tl(TCG_LTU_NE, tmp_7, tmp_3, tmp_5);
	TCGLabel *branch_l_272 = gen_new_label();
	tcg_gen_brcondi_tl(TCG_COND_EQ, tmp_7, 0, branch_l_272);
	tcg_gen_br(l_401);
	gen_set_label(branch_l_272);
	tcg_gen_br(l_258);
	gen_set_label(l_258);
	tcg_gen_br(l_458);
	gen_set_label(l_458);
	tcg_gen_br(exit_458);
	gen_set_label(l_401);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_8, cpu_ia);
	TCGv tmp_9 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_9, tmp_8, arg_2);
	tcg_gen_mov_tl(cpu_pc, tmp_9);
	tcg_gen_br(l_458);
	gen_set_label(exit_458);
	ctx->base.is_jmp = DISAS_NORETURN;
	return true;
}

static bool trans_Bltu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (arg_0 & 0x800) >> 11;
	uint64_t tmp_8 = arg_0 & 0x001;
	uint64_t tmp_9 = (tmp_8 << 1) | tmp_7;
	uint64_t tmp_10 = (arg_0 & 0x7FE) >> 1;
	uint64_t tmp_11 = (tmp_10 << 2) | tmp_9;
	uint64_t tmp_12 = (0b0 << 12) | tmp_11;
	uint64_t tmp_13 = (0b1111111111111111111 << 13) * (tmp_12 & (1 << 13) >> 13);
	uint64_t tmp_14 = tmp_13 | tmp_12;
	tcg_trans_Bltu(ctx, tmp_4, tmp_6, tmp_14);
	return true;
}

static bool tcg_trans_Bgeu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_109 = gen_new_label();
	TCGLabel *l_369 = gen_new_label();
	TCGLabel *exit_347 = gen_new_label();
	TCGLabel *l_347 = gen_new_label();
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_0 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_setcond_tl(TCG_GEU_NE, tmp_7, tmp_3, tmp_5);
	TCGLabel *branch_l_383 = gen_new_label();
	tcg_gen_brcondi_tl(TCG_COND_EQ, tmp_7, 0, branch_l_383);
	tcg_gen_br(l_369);
	gen_set_label(branch_l_383);
	tcg_gen_br(l_109);
	gen_set_label(l_109);
	tcg_gen_br(l_347);
	gen_set_label(l_347);
	tcg_gen_br(exit_347);
	gen_set_label(l_369);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_8, cpu_ia);
	TCGv tmp_9 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_9, tmp_8, arg_2);
	tcg_gen_mov_tl(cpu_pc, tmp_9);
	tcg_gen_br(l_347);
	gen_set_label(exit_347);
	ctx->base.is_jmp = DISAS_NORETURN;
	return true;
}

static bool trans_Bgeu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (arg_0 & 0x800) >> 11;
	uint64_t tmp_8 = arg_0 & 0x001;
	uint64_t tmp_9 = (tmp_8 << 1) | tmp_7;
	uint64_t tmp_10 = (arg_0 & 0x7FE) >> 1;
	uint64_t tmp_11 = (tmp_10 << 2) | tmp_9;
	uint64_t tmp_12 = (0b0 << 12) | tmp_11;
	uint64_t tmp_13 = (0b1111111111111111111 << 13) * (tmp_12 & (1 << 13) >> 13);
	uint64_t tmp_14 = tmp_13 | tmp_12;
	tcg_trans_Bgeu(ctx, tmp_4, tmp_6, tmp_14);
	return true;
}

static bool tcg_trans_Lb(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((((arg_1 & 0x00000000FFFF) >> 0) != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_2, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_gpr[((arg_1 & 0x00000000FFFF) >> 0) / 4]);
	tcg_gen_mov_tl(tmp_2, tmp_3);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_4, tmp_2, ((arg_1 & 0xFFFFFFFF0000) >> 16));
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_qemu_ld_tl(tmp_5, tmp_4, 0, MO_8); // FIXME: no idea about sign
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_ext8s_tl(tmp_6, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_6);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Lb(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = (0xFFFFF << 12) * (arg_2 & (1 << 12) >> 12);
	uint64_t tmp_6 = tmp_5 | arg_2;
	uint64_t tmp_7 = arg_1 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	uint64_t tmp_9 = (tmp_8 << 32) | tmp_6;
	tcg_trans_Lb(ctx, tmp_4, tmp_9);
	return true;
}

static bool tcg_trans_Lh(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((((arg_1 & 0x00000000FFFF) >> 0) != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_2, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_gpr[((arg_1 & 0x00000000FFFF) >> 0) / 4]);
	tcg_gen_mov_tl(tmp_2, tmp_3);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_4, tmp_2, ((arg_1 & 0xFFFFFFFF0000) >> 16));
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_qemu_ld_tl(tmp_5, tmp_4, 0, MO_16); // FIXME: no idea about sign
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_ext16s_tl(tmp_6, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_6);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Lh(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = (0xFFFFF << 12) * (arg_1 & (1 << 12) >> 12);
	uint64_t tmp_6 = tmp_5 | arg_1;
	uint64_t tmp_7 = arg_0 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	uint64_t tmp_9 = (tmp_8 << 32) | tmp_6;
	tcg_trans_Lh(ctx, tmp_4, tmp_9);
	return true;
}

static bool tcg_trans_Lw(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((((arg_1 & 0x00000000FFFF) >> 0) != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_2, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_gpr[((arg_1 & 0x00000000FFFF) >> 0) / 4]);
	tcg_gen_mov_tl(tmp_2, tmp_3);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_4, tmp_2, ((arg_1 & 0xFFFFFFFF0000) >> 16));
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_qemu_ld_tl(tmp_5, tmp_4, 0, MO_32);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_5);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Lw(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = (0xFFFFF << 12) * (arg_2 & (1 << 12) >> 12);
	uint64_t tmp_6 = tmp_5 | arg_2;
	uint64_t tmp_7 = arg_0 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	uint64_t tmp_9 = (tmp_8 << 32) | tmp_6;
	tcg_trans_Lw(ctx, tmp_4, tmp_9);
	return true;
}

static bool tcg_trans_Lbu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((((arg_1 & 0x00000000FFFF) >> 0) != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_2, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_gpr[((arg_1 & 0x00000000FFFF) >> 0) / 4]);
	tcg_gen_mov_tl(tmp_2, tmp_3);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_4, tmp_2, ((arg_1 & 0xFFFFFFFF0000) >> 16));
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_qemu_ld_tl(tmp_5, tmp_4, 0, MO_8); // FIXME: no idea about sign
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_ext8u_tl(tmp_6, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_6);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Lbu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = (0xFFFFF << 12) * (arg_1 & (1 << 12) >> 12);
	uint64_t tmp_6 = tmp_5 | arg_1;
	uint64_t tmp_7 = arg_2 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	uint64_t tmp_9 = (tmp_8 << 32) | tmp_6;
	tcg_trans_Lbu(ctx, tmp_4, tmp_9);
	return true;
}

static bool tcg_trans_Lhu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((((arg_1 & 0x00000000FFFF) >> 0) != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_2, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_gpr[((arg_1 & 0x00000000FFFF) >> 0) / 4]);
	tcg_gen_mov_tl(tmp_2, tmp_3);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_4, tmp_2, ((arg_1 & 0xFFFFFFFF0000) >> 16));
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_qemu_ld_tl(tmp_5, tmp_4, 0, MO_16); // FIXME: no idea about sign
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_ext16u_tl(tmp_6, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_6);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Lhu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = (0xFFFFF << 12) * (arg_2 & (1 << 12) >> 12);
	uint64_t tmp_6 = tmp_5 | arg_2;
	uint64_t tmp_7 = arg_1 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	uint64_t tmp_9 = (tmp_8 << 32) | tmp_6;
	tcg_trans_Lhu(ctx, tmp_4, tmp_9);
	return true;
}

static bool tcg_trans_Sb(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((((arg_1 & 0x00000000FFFF) >> 0) != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_2, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_gpr[((arg_1 & 0x00000000FFFF) >> 0) / 4]);
	tcg_gen_mov_tl(tmp_2, tmp_3);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_4, tmp_2, ((arg_1 & 0xFFFFFFFF0000) >> 16));
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_0 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_andi_tl(tmp_7, tmp_5, 0x000000FF);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_qemu_st_tl(tmp_7, tmp_4, 0, MO_8);
	return true;
}

static bool trans_Sb(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = (0xFFFFF << 12) * (arg_0 & (1 << 12) >> 12);
	uint64_t tmp_6 = tmp_5 | arg_0;
	uint64_t tmp_7 = arg_1 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	uint64_t tmp_9 = (tmp_8 << 32) | tmp_6;
	tcg_trans_Sb(ctx, tmp_4, tmp_9);
	return true;
}

static bool tcg_trans_Sh(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((((arg_1 & 0x00000000FFFF) >> 0) != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_2, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_gpr[((arg_1 & 0x00000000FFFF) >> 0) / 4]);
	tcg_gen_mov_tl(tmp_2, tmp_3);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_4, tmp_2, ((arg_1 & 0xFFFFFFFF0000) >> 16));
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_0 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_andi_tl(tmp_7, tmp_5, 0x0000FFFF);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_qemu_st_tl(tmp_7, tmp_4, 0, MO_16);
	return true;
}

static bool trans_Sh(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = (0xFFFFF << 12) * (arg_0 & (1 << 12) >> 12);
	uint64_t tmp_6 = tmp_5 | arg_0;
	uint64_t tmp_7 = arg_2 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	uint64_t tmp_9 = (tmp_8 << 32) | tmp_6;
	tcg_trans_Sh(ctx, tmp_4, tmp_9);
	return true;
}

static bool tcg_trans_Sw(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((((arg_1 & 0x00000000FFFF) >> 0) != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_2 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_2, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_3, cpu_gpr[((arg_1 & 0x00000000FFFF) >> 0) / 4]);
	tcg_gen_mov_tl(tmp_2, tmp_3);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_4, tmp_2, ((arg_1 & 0xFFFFFFFF0000) >> 16));
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_0 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_qemu_st_tl(tmp_5, tmp_4, 0, MO_32);
	return true;
}

static bool trans_Sw(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = (0xFFFFF << 12) * (arg_0 & (1 << 12) >> 12);
	uint64_t tmp_6 = tmp_5 | arg_0;
	uint64_t tmp_7 = arg_2 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	uint64_t tmp_9 = (tmp_8 << 32) | tmp_6;
	tcg_trans_Sw(ctx, tmp_4, tmp_9);
	return true;
}
#endif

static bool tcg_trans_Addi(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_addi_tl(tmp_5, tmp_3, arg_2);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_5);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Addi(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
#if 0
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0xFFFFF << 12) * (arg_1 & (1 << 12) >> 12);
	uint64_t tmp_8 = tmp_7 | arg_1;
	tcg_trans_Addi(ctx, tmp_4, tmp_6, tmp_8);
#else
    TCGv t0 = tcg_temp_new();
    tcg_gen_addi_tl(t0, get_gpr(ctx, arg_2), sextract32(arg_1, 0, 12));
    set_gpr(ctx, arg_0, t0);
#endif
	return true;
}

#if 0
static bool tcg_trans_Slti(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_setcondi_tl(TCG_LT_NE, tmp_5, tmp_3, arg_2);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_ext32u_i63(tmp_6, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_6);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Slti(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0xFFFFF << 12) * (arg_0 & (1 << 12) >> 12);
	uint64_t tmp_8 = tmp_7 | arg_0;
	tcg_trans_Slti(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Sltiu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_setcondi_tl(TCG_LTU_NE, tmp_5, tmp_3, arg_2);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_ext32u_i63(tmp_6, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_6);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Sltiu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0xFFFFF << 12) * (arg_0 & (1 << 12) >> 12);
	uint64_t tmp_8 = tmp_7 | arg_0;
	tcg_trans_Sltiu(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Xori(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_xori_tl(tmp_5, tmp_3, arg_2);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_5);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Xori(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0xFFFFF << 12) * (arg_1 & (1 << 12) >> 12);
	uint64_t tmp_8 = tmp_7 | arg_1;
	tcg_trans_Xori(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Ori(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_ori_tl(tmp_5, tmp_3, arg_2);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_5);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Ori(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0xFFFFF << 12) * (arg_0 & (1 << 12) >> 12);
	uint64_t tmp_8 = tmp_7 | arg_0;
	tcg_trans_Ori(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Andi(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_andi_tl(tmp_5, tmp_3, arg_2);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_5);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Andi(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0xFFFFF << 12) * (arg_1 & (1 << 12) >> 12);
	uint64_t tmp_8 = tmp_7 | arg_1;
	tcg_trans_Andi(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Slli(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_shli_tl(tmp_6, tmp_3, ((arg_2 & 0x0000001F) ? 1 : 0));
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_6);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Slli(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_0 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0b111111111111111111111111111 << 5) * (arg_1 & (1 << 5) >> 5);
	uint64_t tmp_8 = tmp_7 | arg_1;
	tcg_trans_Slli(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Srli(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_shri_tl(tmp_6, tmp_3, ((arg_2 & 0x0000001F) ? 1 : 0));
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_6);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Srli(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0b111111111111111111111111111 << 5) * (arg_1 & (1 << 5) >> 5);
	uint64_t tmp_8 = tmp_7 | arg_1;
	tcg_trans_Srli(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Srai(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_sari_tl(tmp_6, tmp_3, ((arg_2 & 0x0000001F) ? 1 : 0));
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_6);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Srai(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = (0b111111111111111111111111111 << 5) * (arg_1 & (1 << 5) >> 5);
	uint64_t tmp_8 = tmp_7 | arg_1;
	tcg_trans_Srai(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Add(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_add_tl(tmp_7, tmp_3, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_7);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Add(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_0 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_Add(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Sub(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_sub_tl(tmp_7, tmp_3, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_7);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Sub(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_1 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_Sub(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Sll(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_andi_tl(tmp_7, tmp_5, 0x0000001F);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_shl_tl(tmp_8, tmp_3, tmp_7);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_8);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Sll(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_0 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_Sll(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Srl(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_andi_tl(tmp_7, tmp_5, 0x0000001F);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_shr_tl(tmp_8, tmp_3, tmp_7);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_8);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Srl(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_0 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_2 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_Srl(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Slt(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_setcond_tl(TCG_LT_NE, tmp_7, tmp_3, tmp_5);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_ext32u_i63(tmp_8, tmp_7);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_8);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Slt(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_0 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_2 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_Slt(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Sltu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_setcond_tl(TCG_LTU_NE, tmp_7, tmp_3, tmp_5);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_ext32u_i63(tmp_8, tmp_7);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_8);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Sltu(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_0 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_Sltu(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Xor(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_xor_tl(tmp_7, tmp_3, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_7);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Xor(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_0 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_2 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_1 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_Xor(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Sra(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_andi_tl(tmp_7, tmp_5, 0x0000001F);
	TCGv tmp_8 = tcg_temp_new();
	tcg_gen_shr_tl(tmp_8, tmp_3, tmp_7);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_8);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Sra(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_0 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_2 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_Sra(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Or(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_or_tl(tmp_7, tmp_3, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_7);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_Or(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_1 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_0 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_Or(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_And(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_1 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_3 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_3, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_4 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_4, cpu_gpr[arg_1 / 4]);
	tcg_gen_mov_tl(tmp_3, tmp_4);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGLabel *l_9 = gen_new_label();
	TCGLabel *l_437 = gen_new_label();
	TCGLabel *exit_404 = gen_new_label();
	TCGLabel *l_404 = gen_new_label();
	if (((arg_2 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_437);
	} else {
		tcg_gen_br(l_9);
	}
	gen_set_label(l_9);
	TCGv tmp_5 = tcg_temp_new();
	tcg_gen_movi_tl(tmp_5, 0x00000000);
	tcg_gen_br(l_404);
	gen_set_label(l_404);
	tcg_gen_br(exit_404);
	gen_set_label(l_437);
	TCGv tmp_6 = tcg_temp_new();
	tcg_gen_mov_tl(tmp_6, cpu_gpr[arg_2 / 4]);
	tcg_gen_mov_tl(tmp_5, tmp_6);
	tcg_gen_br(l_404);
	gen_set_label(exit_404);
	TCGv tmp_7 = tcg_temp_new();
	tcg_gen_and_tl(tmp_7, tmp_3, tmp_5);
	TCGLabel *l_250 = gen_new_label();
	TCGLabel *l_15 = gen_new_label();
	TCGLabel *exit_308 = gen_new_label();
	TCGLabel *l_308 = gen_new_label();
	if (((arg_0 != 0x0000) ? 1 : 0)) {
		tcg_gen_br(l_15);
	} else {
		tcg_gen_br(l_250);
	}
	gen_set_label(l_250);
	tcg_gen_br(l_308);
	gen_set_label(l_308);
	tcg_gen_br(exit_308);
	gen_set_label(l_15);
	tcg_gen_mov_tl(cpu_gpr[arg_0 / 4], tmp_7);
	tcg_gen_br(l_308);
	gen_set_label(exit_308);
	return true;
}

static bool trans_And(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_1 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_0 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_2 * 0x0004;
	uint64_t tmp_8 = 0x0000 + tmp_7;
	tcg_trans_And(ctx, tmp_4, tmp_6, tmp_8);
	return true;
}

static bool tcg_trans_Fence(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1)
{
	return true;
}

static bool trans_Fence(DisasContext *ctx, uint64_t arg_0, uint64_t arg_1, uint64_t arg_2)
{
	uint64_t tmp_3 = arg_2 * 0x0004;
	uint64_t tmp_4 = 0x0000 + tmp_3;
	uint64_t tmp_5 = arg_0 * 0x0004;
	uint64_t tmp_6 = 0x0000 + tmp_5;
	uint64_t tmp_7 = arg_1 & 0x001;
	uint64_t tmp_8 = (arg_1 & 0x002) >> 1;
	uint64_t tmp_9 = (tmp_8 << 1) | tmp_7;
	uint64_t tmp_10 = (arg_1 & 0x004) >> 2;
	uint64_t tmp_11 = (tmp_10 << 2) | tmp_9;
	uint64_t tmp_12 = (arg_1 & 0x008) >> 3;
	uint64_t tmp_13 = (tmp_12 << 3) | tmp_11;
	uint64_t tmp_14 = (arg_1 & 0x010) >> 4;
	uint64_t tmp_15 = (tmp_14 << 4) | tmp_13;
	uint64_t tmp_16 = (arg_1 & 0x020) >> 5;
	uint64_t tmp_17 = (tmp_16 << 5) | tmp_15;
	uint64_t tmp_18 = (arg_1 & 0x040) >> 6;
	uint64_t tmp_19 = (tmp_18 << 6) | tmp_17;
	uint64_t tmp_20 = (arg_1 & 0x080) >> 7;
	uint64_t tmp_21 = (tmp_20 << 7) | tmp_19;
	uint64_t tmp_22 = (arg_1 & 0xF00) >> 8;
	uint64_t tmp_23 = (tmp_22 << 8) | tmp_21;
	tcg_trans_Fence(ctx, tmp_4, tmp_6);
	return true;
}
#endif
