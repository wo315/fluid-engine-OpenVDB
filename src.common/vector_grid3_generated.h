// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_VECTORGRID3_JET_FBS_H_
#define FLATBUFFERS_GENERATED_VECTORGRID3_JET_FBS_H_

#include "flatbuffers.h"

#include "basic_types_generated.h"

namespace vox {
namespace fbs {

struct VectorGrid3;

struct VectorGrid3 FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
    enum {
        VT_RESOLUTION = 4,
        VT_GRIDSPACING = 6,
        VT_ORIGIN = 8,
        VT_DATA = 10
    };
    const vox::fbs::Size3 *resolution() const {
        return GetStruct<const vox::fbs::Size3 *>(VT_RESOLUTION);
    }
    const vox::fbs::Vector3D *gridSpacing() const {
        return GetStruct<const vox::fbs::Vector3D *>(VT_GRIDSPACING);
    }
    const vox::fbs::Vector3D *origin() const {
        return GetStruct<const vox::fbs::Vector3D *>(VT_ORIGIN);
    }
    const flatbuffers::Vector<double> *data() const {
        return GetPointer<const flatbuffers::Vector<double> *>(VT_DATA);
    }
    bool Verify(flatbuffers::Verifier &verifier) const {
        return VerifyTableStart(verifier) &&
        VerifyField<vox::fbs::Size3>(verifier, VT_RESOLUTION) &&
        VerifyField<vox::fbs::Vector3D>(verifier, VT_GRIDSPACING) &&
        VerifyField<vox::fbs::Vector3D>(verifier, VT_ORIGIN) &&
        VerifyOffset(verifier, VT_DATA) &&
        verifier.Verify(data()) &&
        verifier.EndTable();
    }
};

struct VectorGrid3Builder {
    flatbuffers::FlatBufferBuilder &fbb_;
    flatbuffers::uoffset_t start_;
    void add_resolution(const vox::fbs::Size3 *resolution) {
        fbb_.AddStruct(VectorGrid3::VT_RESOLUTION, resolution);
    }
    void add_gridSpacing(const vox::fbs::Vector3D *gridSpacing) {
        fbb_.AddStruct(VectorGrid3::VT_GRIDSPACING, gridSpacing);
    }
    void add_origin(const vox::fbs::Vector3D *origin) {
        fbb_.AddStruct(VectorGrid3::VT_ORIGIN, origin);
    }
    void add_data(flatbuffers::Offset<flatbuffers::Vector<double>> data) {
        fbb_.AddOffset(VectorGrid3::VT_DATA, data);
    }
    VectorGrid3Builder(flatbuffers::FlatBufferBuilder &_fbb)
    : fbb_(_fbb) {
        start_ = fbb_.StartTable();
    }
    VectorGrid3Builder &operator=(const VectorGrid3Builder &);
    flatbuffers::Offset<VectorGrid3> Finish() {
        const auto end = fbb_.EndTable(start_, 4);
        auto o = flatbuffers::Offset<VectorGrid3>(end);
        return o;
    }
};

inline flatbuffers::Offset<VectorGrid3> CreateVectorGrid3(
                                                          flatbuffers::FlatBufferBuilder &_fbb,
                                                          const vox::fbs::Size3 *resolution = 0,
                                                          const vox::fbs::Vector3D *gridSpacing = 0,
                                                          const vox::fbs::Vector3D *origin = 0,
                                                          flatbuffers::Offset<flatbuffers::Vector<double>> data = 0) {
    VectorGrid3Builder builder_(_fbb);
    builder_.add_data(data);
    builder_.add_origin(origin);
    builder_.add_gridSpacing(gridSpacing);
    builder_.add_resolution(resolution);
    return builder_.Finish();
}

inline flatbuffers::Offset<VectorGrid3> CreateVectorGrid3Direct(
                                                                flatbuffers::FlatBufferBuilder &_fbb,
                                                                const vox::fbs::Size3 *resolution = 0,
                                                                const vox::fbs::Vector3D *gridSpacing = 0,
                                                                const vox::fbs::Vector3D *origin = 0,
                                                                const std::vector<double> *data = nullptr) {
    return vox::fbs::CreateVectorGrid3(
                                       _fbb,
                                       resolution,
                                       gridSpacing,
                                       origin,
                                       data ? _fbb.CreateVector<double>(*data) : 0);
}

inline const vox::fbs::VectorGrid3 *GetVectorGrid3(const void *buf) {
    return flatbuffers::GetRoot<vox::fbs::VectorGrid3>(buf);
}

inline bool VerifyVectorGrid3Buffer(
                                    flatbuffers::Verifier &verifier) {
    return verifier.VerifyBuffer<vox::fbs::VectorGrid3>(nullptr);
}

inline void FinishVectorGrid3Buffer(
                                    flatbuffers::FlatBufferBuilder &fbb,
                                    flatbuffers::Offset<vox::fbs::VectorGrid3> root) {
    fbb.Finish(root);
}

}  // namespace fbs
}  // namespace vox

#endif  // FLATBUFFERS_GENERATED_VECTORGRID3_JET_FBS_H_
