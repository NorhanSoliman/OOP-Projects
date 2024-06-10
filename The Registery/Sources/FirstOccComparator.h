#ifndef FIRST_OCC_COMPARATOR_H
#define FIRST_OCC_COMPARATOR_H

#include "Comparator.h"

class FirstOccComparator : public Comparator {
public:
    bool compare(AbstractEvent& e1, AbstractEvent& e2) const override;
};

#endif // FIRST_OCC_COMPARATOR_H
