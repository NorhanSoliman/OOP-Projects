#ifndef LAST_OCC_COMPARATOR_H
#define LAST_OCC_COMPARATOR_H

#include "Comparator.h"

class LastOccComparator : public Comparator {
public:
    bool compare(AbstractEvent& e1, AbstractEvent& e2) const override;
};

#endif // LAST_OCC_COMPARATOR_H
