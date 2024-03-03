/*
 * QEMU RISC-V CPU
 *
 * Copyright (c) 2016-2017 Sagar Karandikar, sagark@eecs.berkeley.edu
 * Copyright (c) 2017-2018 SiFive, Inc.
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

#ifndef RISCV_CPU_H
#define RISCV_CPU_H

#include "hw/core/cpu.h"
#include "hw/registerfields.h"
#include "exec/cpu-defs.h"
#include "qom/object.h"
#include "qemu/int128.h"
#include "cpu_bits.h"
#include "qapi/qapi-types-common.h"
#include "cpu-qom.h"

#define gf_todo() g_assert(0 && "implement me")

typedef struct CPUArchState CPUGFState;

#define CPU_RESOLVING_TYPE TYPE_GF_CPU

#if defined(TARGET_GF32)
# define TYPE_GF_CPU_BASE            TYPE_GF_CPU_BASE32
#elif defined(TARGET_GF64)
# define TYPE_GF_CPU_BASE            TYPE_GF_CPU_BASE64
#endif

#define TCG_GUEST_DEFAULT_MO 0

struct CPUArchState {
    target_ulong gpr[32];
    target_ulong pc;

    uint32_t xl;            /* current xlen */
};

/*
 * GFCPU:
 * @env: #CPUGFState
 *
 * A RISCV CPU.
 */
struct ArchCPU {
    CPUState parent_obj;

    CPUGFState env;
};

/**
 * GFCPUClass:
 * @parent_realize: The parent class' realize handler.
 * @parent_phases: The parent class' reset phase handlers.
 *
 * A GF CPU model.
 */
struct GFCPUClass {
    CPUClass parent_class;

    DeviceRealize parent_realize;
    ResettablePhases parent_phases;
};

#include "cpu_user.h"

extern const char * const gf_int_regnames[];

#ifdef TARGET_GF32
#define gf_cpu_mxl(env)  ((void)(env), MXL_RV32)
#endif

int gf_cpu_mmu_index(CPUGFState *env, bool ifetch);

#define cpu_mmu_index gf_cpu_mmu_index

void gf_translate_init(void);

#include "exec/cpu-all.h"

void cpu_get_tb_cpu_state(CPUGFState *env, vaddr *pc,
                          uint64_t *cs_base, uint32_t *pflags);

G_NORETURN void gf_raise_exception(CPUGFState *env,
                                   uint32_t exception, uintptr_t pc);

#endif /* RISCV_CPU_H */
