/*
 * RISC-V emulation for qemu: main translation routines.
 *
 * Copyright (c) 2016-2017 Sagar Karandikar, sagark@eecs.berkeley.edu
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2 or later, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "qemu/osdep.h"
#include "qemu/log.h"
#include "cpu.h"
#include "tcg/tcg-op.h"
#include "disas/disas.h"
#include "exec/cpu_ldst.h"
#include "exec/exec-all.h"
#include "exec/helper-proto.h"
#include "exec/helper-gen.h"

#include "exec/translator.h"
#include "exec/log.h"

#define HELPER_H "helper.h"
#include "exec/helper-info.c.inc"
#undef  HELPER_H

/* global register indices */
static TCGv cpu_gpr[32], cpu_pc;

typedef struct DisasContext {
    DisasContextBase base;
} DisasContext;

static void gf_tr_init_disas_context(DisasContextBase *dcbase, CPUState *cs)
{
}

static void gf_tr_tb_start(DisasContextBase *db, CPUState *cpu)
{
}

static void gf_tr_insn_start(DisasContextBase *dcbase, CPUState *cpu)
{
}

static void gf_tr_translate_insn(DisasContextBase *dcbase, CPUState *cpu)
{
    g_assert(0 && "implement gf_tr_translate_insn");
}

static void gf_tr_tb_stop(DisasContextBase *dcbase, CPUState *cpu)
{
}

static void gf_tr_disas_log(const DisasContextBase *dcbase,
                               CPUState *cpu, FILE *logfile)
{
    fprintf(logfile, "IN: %s\n", lookup_symbol(dcbase->pc_first));
    target_disas(logfile, cpu, dcbase->pc_first, dcbase->tb->size);
}

static const TranslatorOps gf_tr_ops = {
    .init_disas_context = gf_tr_init_disas_context,
    .tb_start           = gf_tr_tb_start,
    .insn_start         = gf_tr_insn_start,
    .translate_insn     = gf_tr_translate_insn,
    .tb_stop            = gf_tr_tb_stop,
    .disas_log          = gf_tr_disas_log,
};

void gen_intermediate_code(CPUState *cs, TranslationBlock *tb, int *max_insns,
                           target_ulong pc, void *host_pc)
{
    DisasContext ctx;

    translator_loop(cs, tb, max_insns, pc, host_pc, &gf_tr_ops, &ctx.base);
}

void gf_translate_init(void)
{
    int i;

    /*
     * cpu_gpr[0] is a placeholder for the zero register. Do not use it.
     * Use the gen_set_gpr and get_gpr helper functions when accessing regs,
     * unless you specifically block reads/writes to reg 0.
     */
    cpu_gpr[0] = NULL;

    for (i = 1; i < 32; i++) {
        cpu_gpr[i] = tcg_global_mem_new(tcg_env,
            offsetof(CPUGFState, gpr[i]), gf_int_regnames[i]);
    }

    cpu_pc = tcg_global_mem_new(tcg_env, offsetof(CPUGFState, pc), "pc");
}
