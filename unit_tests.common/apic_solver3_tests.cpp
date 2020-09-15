// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include "../src.common/apic_solver3.h"
#include "../external/gtest/include/gtest/gtest.h"

using namespace vox;

TEST(ApicSolver3, UpdateEmpty) {
    ApicSolver3 solver;
    
    for (Frame frame; frame.index < 2; ++frame) {
        solver.update(frame);
    }
}
