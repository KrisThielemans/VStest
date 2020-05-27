#include "Derived.h"

namespace sirf {

template<class dataType>
NiftiImageData3DDeformation<dataType>*
NiftiImageData3DDeformation<dataType>::get_inverse_impl_nr(const std::shared_ptr<const float > image_sptr) const
{
    return  new NiftiImageData3DDeformation<dataType>();
}


template class NiftiImageData3DDeformation<float>;
}
