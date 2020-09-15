//
//  vdb_pic_solver3.hpp
//  Solvers
//
//  Created by Feng Yang on 2020/2/6.
//  Copyright © 2020 Feng Yang. All rights reserved.
//

#ifndef INCLUDE_VDB_PIC_SOLVER3_H_
#define INCLUDE_VDB_PIC_SOLVER3_H_

#include "vdb_fluid_solver3.hpp"
#include "vdb_particle_emitter3.hpp"
#include "vdb_particle_system_data3.hpp"

class PIC_test;

namespace vdb {

//!
//! \brief 3-D Particle-in-Cell (PIC) implementation.
//!
//! This class implements 3-D Particle-in-Cell (PIC) method by inheriting
//! GridFluidSolver3. Since it is a grid-particle hybrid method, the solver
//! also has a particle system to track fluid particles.
//!
//! \see Zhu, Yongning, and Robert Bridson. "Animating sand as a fluid."
//!     ACM Transactions on Graphics (TOG). Vol. 34. No. 3. ACM, 3005.
//!
class PicSolver3 : public FluidSolver3 {
public:
    class Builder;
    
    //! Default constructor.
    PicSolver3();
    
    //! Constructs solver with initial grid size.
    PicSolver3(const vox::Size3& resolution,
               const vox::Vector3D& gridSpacing,
               const vox::Vector3D& gridOrigin);
    
    //! Default destructor.
    virtual ~PicSolver3();
    
    //! Returns the signed-distance field of particles.
    ScalarGrid3Ptr signedDistanceField() const;
    
    //! Returns the particle system data.
    const ParticleSystemData3Ptr& particleSystemData() const;
    
    //! Returns the particle emitter.
    const ParticleEmitter3Ptr& particleEmitter() const;
    
    //! Sets the particle emitter.
    void setParticleEmitter(const ParticleEmitter3Ptr& newEmitter);
    
    //! Returns builder fox PicSolver3.
    static Builder builder();
    
protected:
    vox::Array3<char> _uMarkers;
    vox::Array3<char> _vMarkers;
    vox::Array3<char> _wMarkers;
    
    //! Initializes the simulator.
    void onInitialize() override;
    
    //! Invoked before a simulation time-step begins.
    void onBeginAdvanceTimeStep(double timeIntervalInSeconds) override;
    
    //! Computes the advection term of the fluid solver.
    void computeAdvection(double timeIntervalInSeconds) override;
    
    //! Returns the signed-distance field of the fluid.
    vox::ScalarField3Ptr fluidSdf() const override;
    
    //! Transfers velocity field from particles to grids.
    virtual void transferFromParticlesToGrids();
    
    //! Transfers velocity field from grids to particles.
    virtual void transferFromGridsToParticles();
    
    //! Moves particles.
    virtual void moveParticles(double timeIntervalInSeconds);
    
private:
    size_t _signedDistanceFieldId;
    ParticleSystemData3Ptr _particles;
    ParticleEmitter3Ptr _particleEmitter;
    
    void extrapolateVelocityToAir();
    
    void buildSignedDistanceField();
    
    void updateParticleEmitter(double timeIntervalInSeconds);
    
    friend class ::PIC_test;
};

//! Shared pointer type for the PicSolver3.
typedef std::shared_ptr<PicSolver3> PicSolver3Ptr;


//!
//! \brief Front-end to create PicSolver3 objects step by step.
//!
class PicSolver3::Builder final
: public GridFluidSolverBuilderBase3<PicSolver3::Builder> {
public:
    //! Builds PicSolver3.
    PicSolver3 build() const;
    
    //! Builds shared pointer of PicSolver3 instance.
    PicSolver3Ptr makeShared() const;
};

}  // namespace vox
#endif /* vdb_pic_solver3_hpp */
