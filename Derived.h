#pragma once

#include "Base.h"

namespace sirf {


template<class dataType>
class NiftiImageData3DDeformation : public NonRigidTransformation<dataType>
{
public:
    /// Constructor
    NiftiImageData3DDeformation() {}

    std::unique_ptr<NiftiImageData3DDeformation> clone() const
    {
	return std::unique_ptr<NiftiImageData3DDeformation>(this->clone_impl());
    }

    std::unique_ptr<NiftiImageData3DDeformation> get_inverse(const std::shared_ptr<const float > image_sptr = nullptr, const bool use_vtk=false) const
    {
            return std::unique_ptr<NiftiImageData3DDeformation>(this->get_inverse_impl_nr(image_sptr));
    }

protected:
    /// Clone helper function. Don't use.
    virtual NiftiImageData3DDeformation* clone_impl() const
    {
	return new NiftiImageData3DDeformation(*this);
    }

    /// Helper function for get_inverse (NiftyReg). Don't use.
    virtual NiftiImageData3DDeformation* get_inverse_impl_nr(const std::shared_ptr<const float > image_sptr = nullptr) const;
};
}
