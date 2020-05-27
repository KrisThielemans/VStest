
#pragma once
#include <memory>

namespace sirf {

/*!
\ingroup Registration
\brief Base class for non-rigid transformations.

\author Richard Brown
\author CCP PETMR
*/template<class dataType>
class NonRigidTransformation
{
public:

    /// Destructor
    virtual ~NonRigidTransformation() {}

    /*! \brief Get inverse as unique pointer (potentially based on another image).
     *
     * Why would you want to base it on another image? Well, we might have a deformation
     * that takes us from image A to B. We'll probably want the inverse to take us from
     * image B back to A. In this case, use get_inverse(A). This is because the the deformation
     * field is defined for the reference image. In the second case, A is the reference,
     * and B is the floating image.*/
    std::unique_ptr<NonRigidTransformation> get_inverse(const std::shared_ptr<const float > image_sptr = nullptr, const bool use_vtk=false) const
    {
            return std::unique_ptr<NonRigidTransformation>(this->get_inverse_impl_nr(image_sptr));
    }

protected:
    /// Helper function for get_inverse (NiftyReg). Don't use.
    virtual NonRigidTransformation* get_inverse_impl_nr(const std::shared_ptr<const float > image_sptr = nullptr) const = 0;
};
}
