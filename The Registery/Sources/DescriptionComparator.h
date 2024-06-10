#ifndef DESCRIPTION_COMPARATOR_H
#define DESCRIPTION_COMPARATOR_H

#include "Comparator.h"

class DescriptionComparator : public Comparator {
public:
    bool compare(AbstractEvent& e1, AbstractEvent& e2) const override;
};

#endif // DESCRIPTION_COMPARATOR_H
